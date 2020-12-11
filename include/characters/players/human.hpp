#pragma once
#include "player.hpp"

class Human : public Player {
public:
    Human(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, int mana, int speed) :
        Player(name, position, hp = 300, damage = 30, armor_strength = 30, mana = 30, speed = 30) {}
};
