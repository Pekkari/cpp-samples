#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

#include "game/game.hpp"


//Constructor & Destructor
Game::Game(){

    display_listener.get();
    initGame();
    initDisplay();
}
Game::~Game(){
    for ( auto it : chambers_){
        delete it;
    }
    delete display_;
}

//Private Functions
void Game::initGame(){
    mapReader();
}
void Game::initDisplay(){

}


//Functions
void Game::update(){
    //update game logic
}

/*
    Currently obsolete
*/
void Game::render(){
    //pass tile and character data to display class
}

const bool Game::running() const {
    return gameRunning_;
}

void Game::handleInput(){
    if (!events.empty()) {
        std::string input_event_name = events.front().GetName();
        std::cout << "Input event: " << input_event_name << std::endl;
        if (input_event_name == "KeyEsc") {
            std::cout << "Quitting" << std::endl;
            gameRunning_ = false;
        }
        if (input_event_name == "KeyA") {
            //player_.move(sf::Vector2<float> ());
        }
        if (input_event_name == "KeyD") {
            //player_.move(sf::Vector2<float> ());
        }
        if (input_event_name == "KeyW") {
            //player_.move(sf::Vector2<float> ());
        }
        if (input_event_name == "KeyS") {
            //player_.move(sf::Vector2<float> ());
        }
        if (input_event_name == "KeyE") {
            //TODO
        }
        if (input_event_name == "Key1") {
            //TODO
        }
        if (input_event_name == "Key2") {
            //TODO
        }
        if (input_event_name == "Key3") {
            //TODO
        }
        if (input_event_name == "Key4") {
            //TODO
        }
        if (input_event_name == "MouseLeft") {
            //TODO
        }
        if (input_event_name == "MouseLeft") {
            //TODO
        }
        events.pop();
    }

}

void Game::moveCharacters(){

}

/*
    Textfile location must be in the top level of the 'build' directory!!!

    TODO return false if 'error' and TILE POSITION!
*/
bool Game::mapReader() {
    std::ifstream infile;
    infile.open("location.txt");
    std::string line;

    std::vector<std::vector<GameTile*>> tilesMap;
    //std::vector<Character*> charactersMap;
    //TODO Seperate NPC and Enemy vectors
    float column = 0;
    float row = 0;

    while (std::getline(infile, line))
    {
        std::vector<GameTile*> tilesRow;
        //TODO add endpoint for chamber
        for(char& c : line) {
            if ( c == '1'){
                tilesRow.push_back(new GameTile("N/A", sf::Vector2<float> (0.0+mapTileDims_*row, 0.0+mapTileDims_*column), false, false));
                std::cout << "1";
            }
            //TODO call initCharacter method
            else {
                tilesRow.push_back(new GameTile("N/A", sf::Vector2<float> (0.0+mapTileDims_*row, 0.0+mapTileDims_*column), true, false));
                //charactersMap.push_back(initCharacter(c));

                std::cout << "0";
            }
            row++;
        }
        column++;
        std::cout << "\n";
        tilesMap.push_back(tilesRow);
    }
    chambers_.push_back(new Chamber(tilesMap));
    infile.close();
    return true;
}

/*
    Helper method for mapReader()
    TODO position as parameter
*/
Character* Game::initCharacter(char& c){
    return nullptr;
    // TODO return the character that corresponds with the input value

}
