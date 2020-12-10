#include "SFML/draw.hpp"

sf::Sprite Draw::GetSprite() {
    sf::Sprite spr;
    spr.setTexture(tex_);

    spr.setPosition(GetPosition());
    if (GetScale().x != 0 || GetScale().y != 0) {
        sf::IntRect rect = spr.getTextureRect();
        float xscale = GetScale().x / rect.width;
        float yscale = GetScale().y / rect.height;
        spr.setScale(xscale, yscale);
    }
    if (GetFlip()) {
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
