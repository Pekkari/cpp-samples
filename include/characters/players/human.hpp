#include "player.hpp"

class Human : public Player {
public:
    Human(std::string& name, sf::Vector2<float> position, int hp, int mana, int exp, int strength, int armor) :
        Player(name, position, hp = 30, mana = 30, exp = 30, strength = 30, armor = 30) {}
};
