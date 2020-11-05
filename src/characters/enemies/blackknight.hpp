#include "enemy.hpp"

class BlackKnight : public Enemy {


    public:

        // Random hp and dmg, since each enemy should have their own values.
        BlackKnight(std::string& name, sf::Vector2<float> position, int hp, int dmg)
            : Enemy(name, position, hp=100, dmg=75) {}



};
