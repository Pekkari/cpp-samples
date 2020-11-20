#pragma once
#include "player.hpp"

class Frog : public Player {
public:
    Frog(std::string& name, sf::Vector2<float> position, int hp, int mana, int armor_strength, int speed, int damage, int exp) :
        Player(name, position, hp = 10, mana = 10, armor_strength = 10, speed = 10, damage = 10, exp = 10) {}
};
