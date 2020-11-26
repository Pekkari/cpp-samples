#pragma once
#include "characters/character.hpp"
#include "characters/enemies/enemy.hpp"
#include "characters/npcs/npc.hpp"


class Player : public Character {
public:
    Player(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, int mana, int speed) :
        Character(name, position, hp, damage, armor_strength), mana_(mana), speed_(speed) {}

    int getMana() const;

    int getSpeed() const;

    int getExp() const;

    //void deliverAttack(Enemy& enemy, int damage);

    //void absorbAttack(Enemy& enemy, int damage);

    //void interactNPC(NPC& npc);

    void setMana(int value);

    void setSpeed(int value);

    void setExp(int value);

    void consumeItem(int keyPress);

    void interactNPC(NPC& npc);

    CHARACTER_TYPE_t getType() const;

private:
    int mana_; // mana points of player
    int speed_; // speed points of player (depends on boots)
    int max_mana_ = 100;
    int max_speed_ = 100;
};
