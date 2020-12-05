#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

//Every item has a type
enum class ItemType
{
    ITEM_TYPE_WOODEN_SWORD,
    ITEM_TYPE_IRON_SWORD,
    ITEM_TYPE_NANO_SWORD,
    ITEM_TYPE_ARMOR,
    ITEM_TYPE_BOOTS,
    ITEM_TYPE_KEY,
    ITEM_TYPE_MANA_POTION,
    ITEM_TYPE_HEALTH_POTION
};

std::ostream& operator<<(std::ostream& os, ItemType item) {
    switch(item) {
        case ItemType::ITEM_TYPE_WOODEN_SWORD:  os << std::string("ITEM_TYPE_WOODEN_SWORD"); break;
        case ItemType::ITEM_TYPE_IRON_SWORD:  os << std::string("ITEM_TYPE_IRON_SWORD"); break;
        case ItemType::ITEM_TYPE_NANO_SWORD:  os << std::string("ITEM_TYPE_NANO_SWORD"); break;
        case ItemType::ITEM_TYPE_ARMOR:  os << std::string("ITEM_TYPE_ARMOR"); break;
        case ItemType::ITEM_TYPE_BOOTS:  os << std::string("ITEM_TYPE_BOOTS"); break;
        case ItemType::ITEM_TYPE_KEY:  os << std::string("ITEM_TYPE_KEY"); break;
        case ItemType::ITEM_TYPE_MANA_POTION:  os << std::string("ITEM_TYPE_MANA_POTIION"); break;
        case ItemType::ITEM_TYPE_HEALTH_POTION:  os << std::string("ITEM_TYPE_HEALTH_POTION"); break;
    }
    return os;
}

class Item {
public:
    Item(std::string& name, sf::Vector2<float> position) :
        name_(name), position_(position) {}
    virtual ~Item() {};
    std::string getName() const;
    sf::Vector2<float> getPosition() const;
    virtual ItemType getType() const = 0;
    virtual int getValue() const = 0;
    virtual void Draw() const = 0; //This will be SFML method that renders the item
private:
    std::string name_;
    sf::Vector2<float> position_;
    int value_;
    ItemType type_;
};
