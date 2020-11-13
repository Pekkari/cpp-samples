#include <string>
#include <SFML/System/Vector2.hpp>

class InputEvent {
    std::string name_;
    sf::Vector2f position_;
public:
    InputEvent(std::string action) : name_(action) { }
    InputEvent(std::string action, sf::Vector2f position) :
        name_(action), position_(position) { }

    std::string GetName() { return name_; }
    sf::Vector2f GetPosition() { return position_; }
};
