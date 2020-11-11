#include "player.hpp"

class Frog : public Player {
public:
    Frog(std::string& name, sf::Vector2<float> position, int hp, int mana, int exp, int strength, int armor) :
        Player(name, position, hp = 10, mana = 10, exp = 10, strength = 10, armor = 10) {}
};
