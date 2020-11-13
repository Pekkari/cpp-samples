#include <string>
#include <SFML/System/Vector2.hpp>
/*
This is a dummy implementation of the character class. This should be replaced with Garold's version.
*/
class Character {

    public:
        Character(std::string name, sf::Vector2<float> position) : name_(name), position_(position) {}
    private:
        std::string name_;
        sf::Vector2<float> position_;


};
