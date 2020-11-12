#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "items/item.hpp"

class Equipment : public Item {
public:
    Equipment(std::string& name, sf::Vector2<float> position) :
        Item(name, position) {}
    virtual ~Equipment() {};
    virtual sf::Sprite getSprite() const = 0;
private:
};

class Armor : public Equipment{
public:
    Armor(std::string& name, sf::Vector2<float> position);
    virtual ~Armor() {};
    virtual sf::Sprite getSprite() const;
private:
    sf::Sprite sprite_;
    int armor_strength_;
    const int ARMOR_START_VALUE = 50;
};
