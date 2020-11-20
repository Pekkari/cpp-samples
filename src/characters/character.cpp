// Character is an abstract class
// This file contains methods of it

#include "characters/character.hpp"

std::string Character::getName() const {
    return name_;
}

sf::Vector2<float> Character::getPosition() const {
    return position_;
}

std::vector<Item*> Character::getItems() const {
    return items_;
}

void Character::move(sf::Vector2<float> new_position) {
    position_ = new_position;
}

// This will be SFML method that renders the item
void Character::Draw() const {

}
