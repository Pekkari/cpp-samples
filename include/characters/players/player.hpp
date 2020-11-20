#pragma once
#include "characters/character.hpp"
#include "characters/enemies/enemy.hpp"
#include "characters/npcs/npc.hpp"


class Player : public Character {
public:
    Player(std::string& name, sf::Vector2<float> position, int hp, int mana, int armor_strength, int speed, int damage, int exp) :
        Character(name, position), hp_(hp), mana_(mana), armor_strength_(armor_strength), speed_(speed), damage_(damage), exp_(exp) {}

    void pickupItem(Item* item);

    void consumeItem(int keyPress);

    int getHP() const;

    int getMana() const;

    int getArmorStrength() const;

    int getSpeed() const;

    int getDamage() const;

    int getExp() const;

    //void deliverAttack(Enemy& enemy, int damage);

    //void absorbAttack(Enemy& enemy, int damage);

    //void interactNPC(NPC& npc);

    bool isAlive() const;

protected:
    int hp_; // health points
    int mana_; // mana points
    int armor_strength_; // armor_strength points
    int speed_; // speed points (depends on boots)
    int damage_; // damage points player can deliver (depends on sword)
    int exp_; // experience points
    int max_hp_ = 100;
    int max_mana_ = 100;
    int max_armor_strength_ = 100;
    int max_speed_ = 100;
    int max_damage_ = 100; // this really depends on the sword so will probably not be used
    int max_exp_ = 100;
};
