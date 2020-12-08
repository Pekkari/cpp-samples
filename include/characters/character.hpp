#pragma once
#include <string>
#include <vector>
#include <utility>
#include "SFML/System/Vector2.hpp"
#include "items/item.hpp"

// Every character has a type
enum class CharacterType {
    CHARACTER_TYPE_PLAYER,
    CHARACTER_TYPE_ENEMY,
    CHARACTER_TYPE_NPC
};

std::ostream& operator<<(std::ostream& os, CharacterType character) {
    switch(character) {
        case CharacterType::CHARACTER_TYPE_PLAYER:  os << std::string("CHARACTER_TYPE_PLAYER"); break;
        case CharacterType::CHARACTER_TYPE_ENEMY:  os << std::string("CHARACTER_TYPE_ENEMY"); break;
        case CharacterType::CHARACTER_TYPE_NPC:  os << std::string("CHARACTER_TYPE_NPC"); break;
    }
    return os;
}

class Character {
public:
    Character(std::string& name, sf::Vector2<float> position, CharacterType type) :
        name_(name), position_(position), char_type_(type) { }
    Character(std::string& name, sf::Vector2<float> position, int hp, int damage, int armor_strength, CharacterType type) :
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

    void removeItem(ItemType item_type);

    void addItem(Item* item); // usage, e.g.: add the item to player items_

    bool transferItem(ItemType item_type, Character& from); // usage, e.g.: player.transferItem(item_type, npc) where player = to, npc = from

    uint64_t getLastAttackTime() const;

    void setLastAttackTime();

    bool isIdle();

    bool attack(Character& character);

    bool isAlive() const;

    // getType() doesn't have to be virtual char_type_ is shared among Character objects.
    // Each inherited object will call the constructor with an appropriate CharacterType.
    CharacterType getType() const;

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
    CharacterType char_type_;
};