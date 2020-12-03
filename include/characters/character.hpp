#pragma once
#include <string>
#include <vector>
#include <utility>
#include "SFML/System/Vector2.hpp"
#include "items/item.hpp"

// Every character has a type
typedef enum {
    CHARACTER_TYPE_PLAYER,
    CHARACTER_TYPE_ENEMY,
    CHARACTER_TYPE_NPC
} CHARACTER_TYPE_t;

class Character {
public:
    Character(std::string& name, sf::Vector2<float> position, CHARACTER_TYPE_t type) :
        name_(name), position_(position), char_type_(type) { }
    Character(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, CHARACTER_TYPE_t type) :
        name_(name), position_(position), hp_(hp), damage_(damage), armor_strength_(armor_strength), char_type_(type) { }

    ~Character() {
        for (auto it : items_) {
            delete it;
        }
    };

    std::string getName() const;

    sf::Vector2<float> getPosition() const;

    int getHP() const;

    int getDamage() const;

    int getArmorStrength() const;

    void setHP(int value);

    void setDamage(int value);

    void setArmorStrength(int value);

    std::vector<Item*> getItems() const;

    void removeItem(ITEM_TYPE_t item_type);

    void addItem(Item* item); // usage, e.g.: add the item to player items_

    bool transferItem(ITEM_TYPE_t item_type, Character& from); // usage, e.g.: player.transferItem(item_type, npc) where player = to, npc = from

    uint64_t getLastAttackTime() const;

    void setLastAttackTime();

    bool isIdle();

    bool attack(Character& character);

    bool isAlive() const;

    // getType() doesn't have to be virtual char_type_ is shared among Character objects.
    // Each inherited object will call the constructor with an appropriate CHARACTER_TYPE_t.
    CHARACTER_TYPE_t getType() const;



    void move(sf::Vector2<float> new_position);

    void Draw() const; // This will be SFML method that renders the item

protected:
    std::string name_;
    sf::Vector2<float> position_;
    int hp_; // health points of character (player or enemy)
    int damage_; // damage points of character (player or enemy) can deliver (depends on sword)
    int armor_strength_; // armor_strength points of character (player or enemy)
    int max_hp_ = 100;
    int max_damage_ = 100; // this really depends on the sword so will probably not be used
    int max_armor_strength_ = 100;
    std::vector<Item*> items_;
    uint64_t last_attack_time_;
    CHARACTER_TYPE_t char_type_;
};
