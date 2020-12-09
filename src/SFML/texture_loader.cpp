#include <string>
#include <filesystem>

#include "SFML/texture_loader.hpp"

TextureLoader::TextureLoader() {
    for (auto& p : std::filesystem::recursive_directory_iterator("assets"))
        if (p.is_regular_file()) {
            std::string path = p.path().string();
            auto pos = path.find_last_of('/');
            std::string filename = path.substr(pos + 1);
            sf::Texture tex;
            sf::Font font;
            Asset* as;

            if (tex.loadFromFile(path))
                as = new Draw(filename, tex);
            else if (font.loadFromFile(path))
                as = new Text(filename, font);

            assets_.push_back(as);
        }
}

TextureLoader::TextureLoader(std::string path) {
    for (auto& p : std::filesystem::recursive_directory_iterator(path))
        if (p.is_regular_file()) {
            auto pos = path.find_last_of('/');
            std::string filename = path.substr(pos + 1);
            sf::Texture tex;
            sf::Font font;
            Asset* as;

            if (tex.loadFromFile(path))
                as = new Draw(filename, tex);
            if (font.loadFromFile(path))
                as = new Text(filename, font);

            assets_.push_back(as);
        }
}

Draw* TextureLoader::getDraw(std::string filename) {
    for (Asset* asset : assets_)
        if (asset->GetName() == filename) {
            Draw* d = (Draw*) asset;
            return d;
        }

    return nullptr;
}

Text* TextureLoader::getText(std::string filename) {
    for (Asset* asset : assets_)
        if (asset->GetName() == filename) {
            Text* t = (Text*) asset;
            return t;
        }

    return nullptr;
}
