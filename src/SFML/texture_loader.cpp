#include <string>
#include <filesystem>

#include "SFML/texture_loader.hpp"

TextureLoader::TextureLoader() {
    for (auto& p : std::filesystem::recursive_directory_iterator("assets"))
        if (p.is_regular_file()) {
            Asset as(p.path().string());
            assets_.push_back(std::move(as));
        }
}

TextureLoader::TextureLoader(std::string path) {
    for (auto& p : std::filesystem::recursive_directory_iterator(path))
        if (p.is_regular_file()) {
            Asset as(p.path().string());
            assets_.push_back(std::move(as));
        }
}

Asset& TextureLoader::getAsset(std::string filename) {
    for (Asset& asset : assets_)
        if (asset.getFilename() == filename)
            return asset;
    return assets_.back();
}
