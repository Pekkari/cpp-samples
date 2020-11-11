#include "player.hpp"

class Orc : public Player {
public:
    Orc(std::string& name, sf::Vector2<float> position, int hp, int mana, int exp, int strength, int armor) :
        Player(name, position, hp = 20, mana = 20, exp = 20, strength = 20, armor = 20) {}
};
