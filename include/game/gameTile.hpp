#pragma once
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"
class GameTile {
public:
    GameTile(std::string textureName, sf::Vector2f pos, bool passable, bool exit);
    bool setUpSprite(std::string);
    int dimensions() const{return tileDimension_;};
private:
    //TODO
    //Character* occupied_by_;
    int tileDimension_ = 50;
    bool isPassable_;
    bool isExit_;
    sf::Vector2f pos_;
    sf::Texture texture_;
    sf::Sprite sprite_;
};