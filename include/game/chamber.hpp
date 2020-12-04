#pragma once

#include <vector>
#include "game/gameTile.hpp"
#include "characters/enemies/enemy.hpp"
#include "characters/npcs/npc.hpp"

class Chamber {
public:
    //TODO possible initialization parameters for the chambers
    Chamber(std::vector<std::vector<GameTile*>> tiles, std::vector<Enemy*> enemies, std::vector<NPC*> npcs, sf::Vector2f entrance,
        sf::Vector2f exit);
    ~Chamber();

    void setInitialSate();



    sf::Vector2f entrancePos_;
    sf::Vector2f exitPos_;

    std::vector<Enemy*> enemies_;
    std::vector<NPC*> npcs_;

    std::vector<std::vector<GameTile*>> tiles_;
private:



};
