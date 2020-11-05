#include "enemy.hpp"

class Dragon : public Enemy {


    public:

        // Random hp and dmg, since each enemy should have their own values.
        Dragon(std::string& name, sf::Vector2<float> position, int hp, int dmg)
            : Enemy(name, position, hp=50, dmg=40) {}



};
