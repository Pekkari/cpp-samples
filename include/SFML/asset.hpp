#pragma once
#include <string>
#include <SFML/System/Vector2.hpp>

class Asset {
    std::string name_;
    sf::Vector2f position_;
    sf::Vector2f scale_;
    bool flip_;

public:
    Asset() { }
    Asset(std::string name) : name_(name) { }
    Asset(std::string name, sf::Vector2f position,
        sf::Vector2f scale, bool flip) :
        name_(name), position_(position),
        scale_(scale), flip_(flip) { }

    std::string GetName() { return name_; }
    sf::Vector2f GetPosition() { return position_; }
    sf::Vector2f GetScale() { return scale_; }
    bool GetFlip() { return flip_; }
    void SetName(std::string name) { name_ = name; }
    void SetPosition(sf::Vector2f position) { position_ = position; }
    void SetScale(sf::Vector2f scale) { scale_ = scale; }
    void SetFlip(bool flip) { flip_ = flip; }
};
