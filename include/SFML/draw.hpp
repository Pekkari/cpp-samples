#include <string>
#include <SFML/System/Vector2.hpp>

class Draw {
    std::string name_;
    sf::Vector2f position_;
    sf::Vector2f scale_;
    bool flip_;

public:
    Draw(std::string name) : name_(name) { }
    Draw(std::string name, sf::Vector2f position)
        : name_(name), position_(position) { }
    Draw(std::string name, sf::Vector2f position, sf::Vector2f scale)
        : name_(name), position_(position), scale_(scale) { }
    Draw(std::string name, sf::Vector2f position,
        sf::Vector2f scale, bool flip)
        : name_(name), position_(position),
        scale_(scale), flip_(flip) { }

    std::string GetName() { return name_; }
    sf::Vector2f GetPosition() { return position_; }
    sf::Vector2f GetScale() { return scale_; }
    bool GetFlip() { return flip_; }
};
