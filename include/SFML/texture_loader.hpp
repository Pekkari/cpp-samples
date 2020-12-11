#include <map>
#include <string>

#include "SFML/asset.hpp"
#include "SFML/draw.hpp"
#include "SFML/text.hpp"

class TextureLoader {
    std::map<std::string, Asset*> assets_;
public:
    TextureLoader();

    ~TextureLoader() {
        for (auto as : assets_)
            delete as.second;
    }

    TextureLoader(std::string path);

    Draw* getDraw(std::string filename);
    Text* getText(std::string filename="RujisHandwritingFontv.2.0.otf");
};
