#include "items/consumables/consumable.hpp"

//Key methods:
Key::Key(std::string& name, sf::Vector2<float> position) :
    Consumable(name, position) { }

//This will be SFML method that renders the item
void Key::Draw() const {

}

ITEM_TYPE_t Key::getType() const {
    return ITEM_TYPE_KEY;
}

//HealthPotion methods:
HealthPotion::HealthPotion(std::string& name, sf::Vector2<float> position) :
    Potion(name, position) {
    restore_ = RESTORE_START_VALUE;
}

int HealthPotion::getRestore() const {
    return restore_;
}

int HealthPotion::getValue() const {
    return restore_;
}

//This will be SFML method that renders the item
void HealthPotion::Draw() const {

}

ITEM_TYPE_t HealthPotion::getType() const {
    return ITEM_TYPE_HEALTH_POTION;
}

//ManaPotion methods:
ManaPotion::ManaPotion(std::string& name, sf::Vector2<float> position) :
    Potion(name, position) {
    restore_ = RESTORE_START_VALUE;
}

int ManaPotion::getRestore() const {
    return restore_;
}

int ManaPotion::getValue() const {
    return restore_;
}

//This will be SFML method that renders the item
void ManaPotion::Draw() const {

}

ITEM_TYPE_t ManaPotion::getType() const {
    return ITEM_TYPE_MANA_POTION;
}
