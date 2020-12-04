#pragma once

#include <vector>
#include "SFML/display.hpp"
#include "game/chamber.hpp"
#include "characters/players/player.hpp"
#include "SFML/System/Vector2.hpp"

#include "characters/enemies/goblin.hpp"
#include "characters/enemies/blackknight.hpp"
#include "characters/enemies/dragon.hpp"
#include "characters/enemies/finalboss.hpp"

#include "characters/npcs/chest.hpp"
#include "characters/npcs/door.hpp"
#include "characters/npcs/shopkeeper.hpp"
#include "characters/npcs/wizard.hpp"


//Every item has a type
typedef enum
{
    ATTACK_TYPE_NORMAL_HIT,
    ATTACK_TYPE_AREA_SWING
} ATTACK_TYPE_t;

/*
    Class that acts as the game engine
*/
class Game{
public:
    //Constructor
    Game();
    ~Game();

    //Attributes
    Display* display_ = new Display;
    std::future<int> display_listener = display_->GetListenerThread();
    std::queue<InputEvent>& events = display_->GetInputEventQueue();


    //Functions
    void update();
    void render();
    const bool running() const;
    void changeChamber(bool nextChamber);
    bool interactNPC(sf::Vector2<float> targetLoc);

    void handleInput();
    void moveCharacters();
    bool enemySeePlayer(sf::Vector2<float> enemyLocation);
    sf::Vector2<float> playerMovement(sf::Vector2<float> direction);
    Character& playerAttack(sf::Vector2<float> direction, ATTACK_TYPE_t attackType);
    GameTile& gameTileAtLocation(sf::Vector2<float> targetLoc);

    //Init functions
    bool mapReader();
    Enemy* initEnemy(char& c, sf::Vector2<float> location);
    NPC* initNPC(char& c, sf::Vector2<float> location);

private:
    void initGame();
    void initDisplay();

    bool gameRunning_ = true;
    int currentChamber = 0;
    std::vector<Chamber*> chambers_;
    Chamber* playerChamber(){return chambers_[currentChamber];};
    int mapTileDims_ = 50;

    //TODO Player attributes
    Player* player_;
    sf::Vector2<float> playerFacing_ = sf::Vector2f(0.0f, 0.0f);
};
