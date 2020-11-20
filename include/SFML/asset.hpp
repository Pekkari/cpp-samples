#pragma once
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "SFML/draw.hpp"

class Asset {
    sf::Texture tex_;
    std::string filename_;
public:
    Asset(std::string path);

    sf::Sprite getSprite(Draw draw);
    std::string getFilename() { return filename_; };
};
