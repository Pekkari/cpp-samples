#include <string>
#include <SFML/System/Vector2.hpp>

enum class InputType {
    KeyA,
    KeyD,
    KeyW,
    KeyS,
    KeyE,
    KeyR,
    KeyEsc,
    KeySpace,
    Key1,
    Key2,
    Key3,
    Key4,
    Key5,
    MouseLeft,
    MouseRight
};

std::string toString(InputType input) {
    switch(input) {
        case InputType::KeyA:  return std::string("KeyA");
        case InputType::KeyD:  return std::string("KeyD");
        case InputType::KeyW:  return std::string("KeyW");
        case InputType::KeyS:  return std::string("KeyS");
        case InputType::KeyE:  return std::string("KeyE");
        case InputType::KeyR:  return std::string("KeyR");
        case InputType::KeyEsc:  return std::string("KeyEsc");
        case InputType::KeySpace:  return std::string("KeySpace");
        case InputType::Key1:  return std::string("Key1");
        case InputType::Key2:  return std::string("Key2");
        case InputType::Key3:  return std::string("Key3");
        case InputType::Key4:  return std::string("Key4");
        case InputType::Key5:  return std::string("Key5");
        case InputType::MouseLeft:  return std::string("MouseLeft");
        case InputType::MouseRight:  return std::string("MouseRight");
    }
    return std::string();
}

std::ostream& operator<<(std::ostream& os, InputType input) {
    return os << toString(input);
}

class InputEvent {
    InputType name_;
    sf::Vector2f position_;
public:
    InputEvent() { }
    InputEvent(InputType input) : name_(input) { }
    InputEvent(InputType input, sf::Vector2f position) :
        name_(input), position_(position) { }

    std::string GetName() { return toString(name_); }
    sf::Vector2f GetPosition() { return position_; }
};
