#pragma once
#include "player.hpp"

class Orc : public Player {
public:
    Orc(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, int mana, int speed) :
        Player(name, position, hp = 200, damage = 20, armor_strength = 20, mana = 20, speed = 20) {}
};
