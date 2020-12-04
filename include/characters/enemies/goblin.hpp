#pragma once
#include "characters/enemies/enemy.hpp"

class Goblin : public Enemy {


    public:

        // Random hp and dmg, since each enemy should have their own values.
        Goblin(std::string& name, sf::Vector2<float> position, int hp, int dmg)
            : Enemy(name, position, hp=80, dmg=50) {}



};
