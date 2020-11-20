#pragma once
#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "items/item.hpp"

class Character {
public:
    explicit Character(std::string& name, sf::Vector2<float> position) :
        name_(name), position_(position) {}

    virtual ~Character() {};

    std::string getName() const;

    sf::Vector2<float> getPosition() const;

    std::vector<Item*> getItems() const;

    virtual void pickupItem(Item* item) = 0;

    virtual void consumeItem(int keyPress) = 0;

    void move(sf::Vector2<float> new_position);

    virtual void Draw() const = 0; // This will be SFML method that renders the item

protected:
    std::string name_;
    sf::Vector2<float> position_;
    std::vector<Item*> items_;
};
