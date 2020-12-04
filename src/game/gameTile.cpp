#include "game/gameTile.hpp"

GameTile::GameTile(std::string textureName, sf::Vector2f pos, bool passable, bool exit, bool entrance)
    : pos_(pos), isPassable_(passable), isExit_(exit), isEntrance_(entrance) { }

//Placeholder
bool GameTile::setUpSprite(std::string textureName) {
    if(!texture_.loadFromFile(textureName)) {
        return false;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture_);
    sprite.setTextureRect(sf::IntRect(pos_.x,pos_.y,tileDimension_,tileDimension_));
    return true;
}