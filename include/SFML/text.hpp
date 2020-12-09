#include <SFML/Graphics/Text.hpp>

#include "SFML/asset.hpp"

class Text : public Asset {
    sf::Font font_;
    std::string message_;
    int size_ = 24;
public:
    Text(std::string name) : Asset(name) { }
    Text(std::string name, sf::Font font)
        : Asset(name), font_(font) { }
    Text(std::string name, sf::Font font, int size)
        : Asset(name), font_(font), size_(size) { }

    sf::Text GetText(std::string msg);
    const sf::Font& GetFont() { return font_; };
};
