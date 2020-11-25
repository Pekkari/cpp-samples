#pragma once

#include <vector>
#include "SFML/display.hpp"
#include "game/chamber.hpp"
#include "characters/players/player.hpp"
#include "SFML/System/Vector2.hpp"


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

    void handleInput();
    void moveCharacters();

    //Init functions
    bool mapReader();
    Character* initCharacter(char& c);

private:
    void initGame();
    void initDisplay();

    bool gameRunning_ = true;
    int currentChamber = 0;
    std::vector<Chamber*> chambers_;
    int current_;
    int mapTileDims_ = 50;

    //TODO Player attributes
};
