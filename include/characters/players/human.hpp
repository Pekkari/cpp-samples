#pragma once
#include "player.hpp"

class Human : public Player {
public:
    Human(std::string& name, sf::Vector2<float> position, int hp, int mana, int armor_strength, int speed, int damage, int exp) :
        Player(name, position, hp = 30, mana = 30, armor_strength = 30, speed = 30, damage = 30, exp = 30) {}
};
