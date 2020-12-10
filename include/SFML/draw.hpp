#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "SFML/asset.hpp"

class Draw : public Asset {
    sf::Texture tex_;
public:
    Draw(std::string name) : Asset(name) { }
    Draw(std::string name, sf::Texture tex)
        : Asset(name), tex_(tex) { }

    sf::Sprite GetSprite();
    const sf::Texture& GetTexture() { return tex_; };
};
