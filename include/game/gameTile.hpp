#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"
#include "characters/npcs/npc.hpp"

class GameTile {
public:
    GameTile(std::string textureName, sf::Vector2f pos, bool passable, bool exit, bool entrance);
    bool setUpSprite(std::string);
    int dimensions() const{return tileDimension_;};
    bool isPassable_;
    sf::Vector2<float> position() const {return pos_;};
    bool exit() const {return isExit_;};
    bool entrance() const {return isEntrance_;};
    void setOccupied(NPC* npc) { occupied_by_ = npc; };
    NPC* getOccupied() {return occupied_by_;};
    std::string& GetName() { return name_; }

private:
    NPC* occupied_by_ = nullptr;
    int tileDimension_ = 50;

    bool isExit_;
    bool isEntrance_;
    sf::Vector2<float> pos_;
    std::string name_;
};
