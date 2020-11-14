#include "items/item.hpp"

std::string Item::getName() const {
    return name_;
}

sf::Vector2<float> Item::getPosition() const {
    return position_;
}
