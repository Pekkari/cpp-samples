#include <iostream>
#include "SFML/asset.hpp"

Asset::Asset(std::string path) {
    tex_.loadFromFile(path);

    auto pos = path.find_last_of('/');
    filename_ = path.substr(pos + 1);
}

sf::Sprite Asset::getSprite(Draw draw) {
    sf::Sprite spr;
    sf::Vector2f scale = draw.GetScale();
    sf::Vector2f position = draw.GetPosition();
    bool flip = draw.GetFlip();
    spr.setTexture(tex_);

    spr.setPosition(position);
    if (scale.x != 0 || scale.y != 0)
        spr.setScale(scale);
    if (flip) {
        sf::IntRect rect = spr.getTextureRect();
        spr.setTextureRect(
            sf::IntRect(
                rect.width,
                0,
                -rect.width,
                rect.height
            )
        );
    }

    return spr;
}
