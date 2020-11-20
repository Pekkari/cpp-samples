#pragma once
#include "player.hpp"

class Orc : public Player {
public:
    Orc(std::string& name, sf::Vector2<float> position, int hp, int mana, int armor_strength, int speed, int damage, int exp) :
        Player(name, position, hp = 20, mana = 20, armor_strength = 20, speed = 20, damage = 20, exp = 20) {}
};
