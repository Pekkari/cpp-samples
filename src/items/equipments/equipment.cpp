//Equipment is an abstract class
//This file contains methods of it
//and all its sub-classes

#include "items/equipments/equipment.hpp"

//Armor methods:
Armor::Armor(std::string& name, sf::Vector2<float> position) :
    Equipment(name, position) {
    armor_strength_ = ARMOR_START_VALUE;
}

int Armor::getStrength() const {
    return armor_strength_;
}

int Armor::getValue() const {
    return armor_strength_;
}

//This will be SFML method that renders the item
void Armor::Draw() const {

}

ITEM_TYPE_t Armor::getType() const {
    return ITEM_TYPE_ARMOR;
}

//Boots methods:
Boots::Boots(std::string& name, sf::Vector2<float> position) :
    Equipment(name, position) {
    speed_ = SPEED_START_VALUE;
}

int Boots::getSpeed() const {
    return speed_;
}

int Boots::getValue() const {
    return speed_;
}

//This will be SFML method that renders the item
void Boots::Draw() const {

}

ITEM_TYPE_t Boots::getType() const {
    return ITEM_TYPE_BOOTS;
}


//Wooden sword methods:
WoodenSword::WoodenSword(std::string& name, sf::Vector2<float> position) :
    Weapon(name, position) {
    damage_ = DAMAGE_START_VALUE;
}

int WoodenSword::getDamage() const {
    return damage_;
}

int WoodenSword::getValue() const {
    return damage_;
}

//This will be SFML method that renders the item
void WoodenSword::Draw() const {

}

ITEM_TYPE_t WoodenSword::getType() const {
    return ITEM_TYPE_WOODEN_SWORD;
}

//Iron sword methods:
IronSword::IronSword(std::string& name, sf::Vector2<float> position) :
    Weapon(name, position) {
    damage_ = DAMAGE_START_VALUE;
}

int IronSword::getDamage() const {
    return damage_;
}

int IronSword::getValue() const {
    return damage_;
}

//This will be SFML method that renders the item
void IronSword::Draw() const {

}

ITEM_TYPE_t IronSword::getType() const {
    return ITEM_TYPE_IRON_SWORD;
}

//Nano sword methods:
NanoSword::NanoSword(std::string& name, sf::Vector2<float> position) :
    Weapon(name, position) {
    damage_ = DAMAGE_START_VALUE;
}

int NanoSword::getDamage() const {
    return damage_;
}

int NanoSword::getValue() const {
    return damage_;
}

//This will be SFML method that renders the item
void NanoSword::Draw() const {

}

ITEM_TYPE_t NanoSword::getType() const {
    return ITEM_TYPE_NANO_SWORD;
}
