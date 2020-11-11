#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "items/item.hpp"

class Character {
public:
    explicit Character(std::string& name, sf::Vector2<float> position) :
        name_(name), position_(position) {}

    virtual ~Character() {};

    std::string getName() const;

    sf::Vector2<float> getPosition() const;

    sf::Sprite getSprite() const;

    std::vector<Item*> getItems() const;

    void addItem(Item& item);

    void removeItem(Item& item);

    void move(sf::Vector2<float> direction);

private:
    std::string name_;
    sf::Vector2<float> position_;
    sf::Sprite sprite_;
    std::vector<Item*> items_;
};
