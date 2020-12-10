#include "SFML/text.hpp"

sf::Text Text::GetText(std::string msg) {
    sf::Text text(msg, font_, size_);
    text.setPosition(GetPosition());
    if (GetScale().x != 0 || GetScale().y != 0)
        text.setScale(GetScale());

    // Since there is no rect wrapper, flip
    // doesn't make sense here
    return text;
}
