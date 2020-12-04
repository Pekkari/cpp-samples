#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>

#include "game/game.hpp"


//Constructor & Destructor
Game::Game(){

    display_listener.get();
    initGame();
    initDisplay();
}
Game::~Game(){
    delete player_;
    for ( auto it : chambers_){
        delete it;
    }
    delete display_;
}

//Private Functions
void Game::initGame(){
    mapReader();
    std::string playerName = "test";
    player_ = new Player(playerName, playerChamber()->entrancePos_, 500, 100, 1, 5, 10);
    for ( auto it : playerChamber()->tiles_ ){
        for ( auto i : it ){
            std::cout << " (" <<i->position().x  << "," << i->position().y << ") " ;
        }
        std::cout << std::endl;
    }
}
void Game::initDisplay(){

}


//Functions

//Calculate new position for the enemy, also used in determining whether the enemy sees the player

sf::Vector2<float> positionVector(sf::Vector2<float> loc, sf::Vector2<float> targetLoc){
    //std::cout << "ENEMY --- x: " << loc.x << " - y: " << loc.y <<std::endl;
    float speed = 10;
    sf::Vector2<float> dirVector = targetLoc - loc;
    float hyp = std::hypot(dirVector.x, dirVector.y);
    dirVector /= hyp;
    return dirVector*speed + loc;
}

//Check if the attacker has range
bool isInRange(Character& attacker, Character& attackee){
    sf::Vector2<float> dirVector = attacker.getPosition() - attackee.getPosition();
    float dist = std::hypot(dirVector.x, dirVector.y);
    //attacker range here
    if ( 10 >= dist ) return true;
    else return false;
}

//Update enemy logic
void Game::update(){
    int i = 0;
    for ( auto enemy : playerChamber()->enemies_){
        //Check if the enemy is dead, remove if it is
        if ( enemy->getHP() < 1 ) {
            std::vector<Enemy *> vec = playerChamber()->enemies_;
            vec.erase(next(begin(vec), i));
            delete enemy;
        }else{
            std::cout << "ENEMY --- x-coordinate: " << enemy->getPosition().x << " --- y-coordinate: " <<  enemy->getPosition().y << std::endl;
            //1st Check if enemy is idle and player is near
            //2nd If idle, check if in attack range and attack
            //3nd else move towards player
            //std::cout << "Update Enemy logic\n";
            if ( enemySeePlayer(enemy->getPosition()) ){
                if ( isInRange(*enemy, *player_) ){
                    if (enemy->attack(*player_)) {
                        std::cout << "PLAYER DEAD!" <<std::endl;
                    }
                    std::cout << "ENEMY ATTACKED, PLAYER HP: " << player_->getHP() << std::endl;
                    //TODO if attack returns true, player died!
                }else{
                    enemy->move(positionVector(enemy->getPosition(), player_->getPosition()));
                }
            }
        }
        i++;
    }
}

/*  Checks if the enemy is able to see the player, too long distances or walls in
    the way block vision
*/
bool Game::enemySeePlayer(sf::Vector2<float> enemyLocation){
    sf::Vector2<float> distVector = player_->getPosition() - enemyLocation;
    float hypot = std::hypot(distVector.x, distVector.y);
    if ( hypot > 300 ){
        return false;
    }else{
        sf::Vector2<float> newLoc = positionVector(enemyLocation, player_->getPosition());
        int j = hypot/50;
        for (int i = 0; i < j; i++){
            newLoc = positionVector(newLoc, player_->getPosition());
            if ( !gameTileAtLocation(newLoc).isPassable_ ) {
                //std::cout << "ENEMY CANNOT SEE THE PLAYER!" << std::endl;
                return false;
            }
        }
        std::cout << "ENEMY SPOTTED THE PLAYER!" << std::endl;
        return true;
    }
}

/*
    Currently obsolete
    Maybe pass game tiles to display class?
*/
void Game::render(){
    //pass tile and character data to display class
}

const bool Game::running() const {
    return gameRunning_;
}

//True if moving to the next chamber, false if moving to the previous
void Game::changeChamber(bool nextChamber) {
    if ( !nextChamber && currentChamber > 0 ) {
        currentChamber--;
        player_->move(playerChamber()->exitPos_);
        std::cout << "PREVIOUS CHAMBER!" << std::endl;
    }
    if (nextChamber) {
        currentChamber++;
        player_->move(playerChamber()->entrancePos_);
        std::cout << "NEXT CHAMBER!" << std::endl;
    }
}

bool Game::interactNPC(sf::Vector2<float> targetLoc){
    NPC* npc = gameTileAtLocation(targetLoc).getOccupied();
    if (npc){
        std::cout << "PLAYER INTERACT WITH NPC" << std::endl;
        return true;
    }else{
        return false;
    }
}

void Game::handleInput(){
    std::cout << "PLAYER --- x-coordinate: " << player_->getPosition().x << " --- y-coordinate: " <<  player_->getPosition().y << std::endl;
    if (!events.empty()) {
        std::string input_event_name = events.front().GetName();
        std::cout << "Input event: " << input_event_name << std::endl;
        if (input_event_name == "KeyEsc") {
            std::cout << "Quitting" << std::endl;
            gameRunning_ = false;
        }
        if (input_event_name == "KeyA") {
            //Direction left
            sf::Vector2<float> dir = sf::Vector2<float>(-10, 0);
            //Update the direction the player is facing
            playerFacing_ = dir;
            sf::Vector2<float> newLoc = playerMovement(dir);
            if ( gameTileAtLocation(newLoc).isPassable_ ) player_->move(newLoc);
        }
        if (input_event_name == "KeyD") {
            //Direction right
            sf::Vector2<float> dir = sf::Vector2<float>(10, 0);
            //Update the direction the player is facing
            playerFacing_ = dir;
            sf::Vector2<float> newLoc = playerMovement(dir);
            if ( gameTileAtLocation(newLoc).isPassable_ ) player_->move(newLoc);
        }
        if (input_event_name == "KeyW") {
            //Direction up
            sf::Vector2<float> dir = sf::Vector2<float>(0, -10);
            //Update the direction the player is facing
            playerFacing_ = dir;
            sf::Vector2<float> newLoc = playerMovement(dir);
            if ( gameTileAtLocation(newLoc).isPassable_ ) player_->move(newLoc);
        }
        if (input_event_name == "KeyS") {
            //Direction down
            sf::Vector2<float> dir = sf::Vector2<float>(0, 10);
            //Update the direction the player is facing
            playerFacing_ = dir;
            sf::Vector2<float> newLoc = playerMovement(dir);
            if ( gameTileAtLocation(newLoc).isPassable_ ) player_->move(newLoc);
        }
        if (input_event_name == "KeyE") {
            //If player is at exit, change to next chamber
            if ( gameTileAtLocation(player_->getPosition()).exit() ){
                changeChamber(true);
            }
            //If player is at exit, change to previous chamber
            if ( gameTileAtLocation(player_->getPosition()).entrance() ){
                changeChamber(false);
            }
            //Try to interract with an NPC
            sf::Vector2<float> newLoc = playerMovement(playerFacing_);
            if (interactNPC(newLoc)){

            }
        }
        if (input_event_name == "Key1") {
            //Consume Health Potion
            //player_->consumeItem(ITEM_TYPE_HEALTH_POTION);

        }
        if (input_event_name == "Key2") {
            //Consume Health Potion
            //player_->consumeItem(ITEM_TYPE_MANA_POTION);
        }
        if (input_event_name == "Key3") {
            //TODO
        }
        if (input_event_name == "Key4") {
            //TODO
        }
        if (input_event_name == "MouseLeft") {
            Character& target = playerAttack(playerFacing_, ATTACK_TYPE_NORMAL_HIT);
            if (player_->attack(target) ){
                //Player killed a monster, add experience
                player_->setExp(player_->getExp() + 10);

                //If the enemy had items give them to the player
                for ( auto item : target.getItems() ){
                    player_->transferItem(item->getType(), target);
                }
            }
        }
        if (input_event_name == "MouseRight") {
            //Character& target = playerAttack(playerFacing_, ATTACK_TYPE_AREA_SWING);
            //if (player_->attack(target) ){
                //Player killed a monster, add experience
                /*player_->setExp(player_->getExp() + 10);

                //If the enemy had items give them to the player
                for ( auto item : target.getItems() ){
                    player_->transferItem(item->getType(), target);
                }*/
            //}
        }
        events.pop();
    }

}

sf::Vector2<float> Game::playerMovement(sf::Vector2<float> direction){
    return direction + player_->getPosition();
}


//Handle player attack
Character& Game::playerAttack(sf::Vector2<float> direction, ATTACK_TYPE_t attackType){
    //Use the player's range instead of a multiple and modify the range if the attack is area swing

    float width = 20.0f;

    if ( attackType == ATTACK_TYPE_AREA_SWING ){
        width = 30.0f;
    }

    sf::Vector2<float> playerPos = player_->getPosition();
    sf::Vector2<float> attackVector = (playerPos + direction)*2.0f;

    if ( attackVector.x < 0 ) attackVector = sf::Vector2<float>(0.0f, 0.0f);
    if ( attackVector.y < 0 ) attackVector = sf::Vector2<float>(0.0f, 0.0f);

    std::cout << "MAX RANGE OF ATTACK --- X: "  << attackVector.x << " - Y: " << attackVector.y << std::endl;

    //Check if horizontal attack
    if ( direction.y == 0.0f){
        for ( auto enemy : playerChamber()->enemies_){
            sf::Vector2<float> enemyPos = enemy->getPosition();
            //Attack to right
            if ( enemyPos.x <= attackVector.x && enemyPos.x >= playerPos.x ){
                if ( enemyPos.y <= (attackVector.y+width/2) && enemyPos.y >= (attackVector.y-width/2)){
                    return *enemy;
                }
            }
            //Attack to left
            if ( enemyPos.x >= attackVector.x && enemyPos.x <= playerPos.x){
                if ( enemyPos.y <= (attackVector.y+width/2) && enemyPos.y >= (attackVector.y-width/2)){
                    return *enemy;
                }
            }
        }
    }
    //Else its a vertical attack
    else{
        for ( auto enemy : playerChamber()->enemies_){
            sf::Vector2<float> enemyPos = enemy->getPosition();
            //Attack to above
            if ( enemyPos.y <= attackVector.y && enemyPos.y >= playerPos.y ){
                if ( enemyPos.x <= (attackVector.x+width/2) && enemyPos.x >= (attackVector.x-width/2)){
                    return *enemy;
                }
            }
            //Attack to below
            if ( enemyPos.y >= attackVector.y && enemyPos.y <= playerPos.y ){
                if ( enemyPos.x <= (attackVector.x+width/2) && enemyPos.x >= (attackVector.x-width/2)){
                    return *enemy;
                }
            }
        }
    }
    return *player_;
}


//Checks if the gameTile at the location is passable
GameTile& Game::gameTileAtLocation(sf::Vector2<float> targetLoc){
    int row = floor(targetLoc.y / mapTileDims_);
    int column = floor(targetLoc.x / mapTileDims_);
    //std::cout << "Target location - x: " << targetLoc.x << " - y: " << targetLoc.y << std::endl;
    //std::cout << "Tile at location - x: " << playerChamber()->tiles_[row][column]->position().x << " - y: " << playerChamber()->tiles_[row][column]->position().y << std::endl;
    return *playerChamber()->tiles_[row][column];
}

/*
    Textfile location must be in the top level of the 'build' directory!!!

    TODO return false if 'error' and TILE POSITION!

    Text file should be formatted like this
    111111
    120031
    111111
    Whole area must be contained within 1's (Wall tile) so the player wont move out of the map, and
    with the current implementation cause a segmentation fault due to gameTilePassable accessing nonexistant memory.

    Works if whole chamber is contained inside walls, like it should be.

*/
bool Game::mapReader() {
    std::ifstream infile;
    infile.open("location.txt");
    std::string line;

    std::vector<std::vector<GameTile*>> tilesMap;
    float column = 0;
    float row = 0;

    std::vector<Enemy*> enemies;
    std::vector<NPC*> npcs;

    sf::Vector2f entrance = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f exit = sf::Vector2f(0.0f, 0.0f);
    sf::Vector2f currentLocation = sf::Vector2f(0.0f, 0.0f);

    while (std::getline(infile, line))
    {
        if ( line == "new" ){
            std::cout << "\n";
            std::cout << "entrance: " << "x: " << entrance.x  << " --- y: "  << entrance.y  << "!\n";
            chambers_.push_back(new Chamber(tilesMap, enemies, npcs, entrance, exit));

            tilesMap.clear();
            column = 0;
            row = 0;

            enemies.clear();
            npcs.clear();

            entrance = sf::Vector2f(0.0f, 0.0f);
            exit = sf::Vector2f(0.0f, 0.0f);
            currentLocation = sf::Vector2f(0.0f, 0.0f);

        }else{

            std::vector<GameTile*> tilesRow;
            for(char& c : line) {

                currentLocation = sf::Vector2<float>(0.0+mapTileDims_*row, 0.0+mapTileDims_*column);

                //Floor
                if ( c == '0'){
                    tilesRow.push_back(new GameTile("N/A", currentLocation, true, false, false));
                    std::cout << "0";
                }
                //Wall
                else if ( c == '1'){
                    tilesRow.push_back(new GameTile("N/A", currentLocation, false, false, false));
                    std::cout << "1";
                }
                 //Entrance
                else if ( c == '2'){
                    tilesRow.push_back(new GameTile("N/A", currentLocation, true, false, true));
                    entrance = sf::Vector2<float> (0.0+mapTileDims_*row, 0.0+mapTileDims_*column);
                    std::cout << "2";
                }
                //Exit
                else if ( c == '3'){
                    tilesRow.push_back(new GameTile("N/A", currentLocation, true, true, false));
                    exit = sf::Vector2<float> (0.0+mapTileDims_*row, 0.0+mapTileDims_*column);
                    std::cout << "3";
                }
                //Create NPC
                else if ( ((int)c) - ((int)'0') <= 9 ){
                    //npcs.push_back(initNPC(c));
                    tilesRow.push_back(new GameTile("N/A", currentLocation, true, false, false));
                    //TODO add occupied by
                    std::cout << c;
                }
                //Create enemy
                else {
                    enemies.push_back(initEnemy(c, currentLocation));
                    tilesRow.push_back(new GameTile("N/A", currentLocation, true, false, false));
                    //TODO add occupied by
                    std::cout << c;
                }
                row++;
            }
            std::cout << "\n";
            row = 0;
            column++;
            tilesMap.push_back(tilesRow);
        }
    }
    std::cout << "\n";
    std::cout << "entrance: " << "x: " << entrance.x  << " --- y: "  << entrance.y  << "!\n";
    chambers_.push_back(new Chamber(tilesMap, enemies, npcs, entrance, exit));
    infile.close();
    return true;
}

/*
    Helper methods for mapReader()
*/
Enemy* Game::initEnemy(char& c, sf::Vector2<float> location){
    if ( c == 'f'){
        std::string name = "Final Boss";
        return new Goblin(name, location, 10, 2);
    }else if ( c == 'b') {
        std::string name = "Black Knight";
        return new Goblin(name, location, 10, 2);
    }else if ( c == 'd') {
        std::string name = "Dragon";
        return new Goblin(name, location, 10, 2);
    }else{
        //Else its a goblin, should be letter 'g'
        std::string name = "Gobo the Tester";
        return new Goblin(name, location, 10, 20);
    }
}
//TODO add different item vectors to different chests
NPC* Game::initNPC(char& c, sf::Vector2<float> location){
    if ( c == '4'){
        std::string name = "Door";
        return new Door(name, location);
    }else if ( c == '5') {
        std::string name = "Wooden Chest";
        return new Chest(name, location);
    }else if ( c == '6') {
        std::string name = "Gold Chest";
        return new Chest(name, location);
    }else if ( c == '7') {
        std::string name = "Legendary Chest";
        return new Chest(name, location);
    }else if ( c == '8') {
        std::string name = "ShopKeeper";
        return new ShopKeeper(name, location);
    }else{
        //Else its a Wizard, should be letter '9'
        std::string name = "Wizard";
        return new Wizard(name, location);
    }

}
