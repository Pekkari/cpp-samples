#include "characters/character.hpp"


class Player : public Character {
public:
    Player(std::string& name, sf::Vector2<float> position, int hp, int mana, int exp, int strength, int armor) :
        Character(name, position), hp_(hp), mana_(mana), exp_(exp), strength_(strength), armor_(armor) {}

    int getHP() const;

    int getMana() const;

    int getStrength() const;

    int getArmor() const;

    //void deliverAttack(Enemy& enemy, int damage);

    //void absorbAttack(Enemy& enemy, int damage);

    //void interactNPC(NPC& npc);

    bool isAlive() const;

private:
    int hp_; // health points
    int mana_; // mana points
    int exp_; // experience points
    int strength_; // strength points
    int armor_; // armor points
};
