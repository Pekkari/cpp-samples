#include "npc.hpp"

class Door : public NPC {


    public:


        Door(std::string& name, sf::Vector2<float> position)
            : NPC(name, position) {}

        bool isLocked() const;
        bool open();
        

    private:
        bool isLocked_;

        
};
