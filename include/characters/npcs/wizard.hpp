#include "npc.hpp"

class Wizard : public NPC {


    public:


        Wizard(std::string& name, sf::Vector2<float> position)
            : NPC(name, position, NPC_WIZARD) {}





};
