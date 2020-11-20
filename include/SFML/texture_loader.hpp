#include <list>
#include <string>

#include "SFML/asset.hpp"

class TextureLoader {
    std::list<Asset> assets_;
public:
    TextureLoader();
    TextureLoader(std::string path);

    Asset& getAsset(std::string filename);
};
