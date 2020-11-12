#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Item {
public:
    Item(std::string& name, sf::Vector2<float> position) :
        name_(name), position_(position) {}
    virtual ~Item() {};
    std::string getName() const;
    sf::Vector2<float> getPosition() const;
    sf::Sprite getSprite() const;
    virtual sf::Sprite getSprite() const = 0;
private:
    std::string name_;
    sf::Vector2<float> position_;
};
