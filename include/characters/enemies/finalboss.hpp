#include "characters/enemies/enemy.hpp"

class FinalBoss : public Enemy {


    public:

        // Random hp and dmg, since each enemy should have their own values.
        FinalBoss(std::string& name, sf::Vector2<float> position, int hp, int dmg)
            : Enemy(name, position, hp=500, dmg=125) {}



};
