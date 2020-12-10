#include <list>
#include <string>

#include "SFML/asset.hpp"
#include "SFML/draw.hpp"
#include "SFML/text.hpp"

class TextureLoader {
    std::list<Asset*> assets_;
public:
    TextureLoader();

    ~TextureLoader() {
        for (Asset* as : assets_)
            delete as;
    }

    TextureLoader(std::string path);

    Draw* getDraw(std::string filename);
    Text* getText(std::string filename="RujisHandwritingFontv.2.0.otf");
};
