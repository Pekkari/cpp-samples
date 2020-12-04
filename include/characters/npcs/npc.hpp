#pragma once

#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "characters/character.hpp"

typedef enum {
    NPC_DOOR,
    NPC_CHEST,
    NPC_SHOPKEEPER,
    NPC_WIZARD
} NPC_TYPE_t;

class NPC : public Character {


    public:


        NPC(std::string& name, sf::Vector2<float> position, NPC_TYPE_t type)
            : npc_type_(type), Character(name, position, CHARACTER_TYPE_NPC) {}

        NPC_TYPE_t getNPCType() const;


    private:
        NPC_TYPE_t npc_type_;
        
};
