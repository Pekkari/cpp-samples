#pragma once

#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "characters/character.hpp"

class NPC : public Character {


    public:


        NPC(std::string& name, sf::Vector2<float> position)
            : Character(name, position, CHARACTER_TYPE_NPC) {}
        
    
   




    private:

        
};
