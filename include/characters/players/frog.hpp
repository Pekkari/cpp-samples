#pragma once
#include "player.hpp"

class Frog : public Player {
public:
    Frog(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, int mana, int speed) :
        Player(name, position, hp = 100, damage = 10, armor_strength = 10, mana = 10, speed = 10) {}
};
