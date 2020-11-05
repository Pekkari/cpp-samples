#include <string>

class NPC : public Character {


    public:


        NPC(std::string& name, sf::Vector2<float> position)
            : Character(name, position) {}


    // Not yet defined how the NPCs are keeping the items they are supposed to give.



};
