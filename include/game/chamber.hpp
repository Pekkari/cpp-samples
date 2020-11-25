#pragma once

#include <vector>
#include "game/gameTile.hpp"


class Chamber {
public:
    //TODO possible initialization parameters for the chambers
    Chamber(std::vector<std::vector<GameTile*>> tiles);
    ~Chamber();

    void setInitialSate();
    sf::Vector2f entrancePos_;
    sf::Vector2f exitPos_;

private:
    std::vector<std::vector<GameTile*>> tiles_;

    //Enemies?
    //NPC's?
    //std::vector<Character*> characters_;
};