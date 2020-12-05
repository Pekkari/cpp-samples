#pragma once
#include "characters/character.hpp"
#include "characters/npcs/npc.hpp"

class Player : public Character {
public:
    Player(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, int mana, int speed) :
        Character(name, position, hp, damage, armor_strength, CharacterType::CHARACTER_TYPE_PLAYER), mana_(mana), speed_(speed) {}

    int getMana() const;

    int getSpeed() const;

    int getExp() const;

    void setMana(int value);

    void setSpeed(int value);

    void setExp(int value);

    void consumeItem(ItemType item_type);

    void interactNPC(NPC& npc);

    CharacterType getType() const;

private:
    int mana_; // mana points of player
    int speed_; // speed points of player (depends on boots)
    int exp_ = 0; // experience points of player
    int max_mana_ = 100;
    int max_speed_ = 100;
    int max_exp_ = 100;
};
