#pragma once

#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "characters/character.hpp"

enum class NPCType {
    NPC_DOOR,
    NPC_CHEST,
    NPC_SHOPKEEPER,
    NPC_WIZARD
};

std::ostream& operator<<(std::ostream& os, NPCType npc) {
    switch(npc) {
        case NPCType::NPC_DOOR:  os << std::string("NPC_DOOR"); break;
        case NPCType::NPC_CHEST:  os << std::string("NPC_CHEST"); break;
        case NPCType::NPC_SHOPKEEPER:  os << std::string("NPC_SHOPKEEPER"); break;
        case NPCType::NPC_WIZARD:  os << std::string("NPC_WIZARD"); break;
    }
    return os;
}

class NPC : public Character {


    public:


        NPC(std::string& name, sf::Vector2<float> position, NPCType type)
            : npc_type_(type), Character(name, position,  CharacterType::CHARACTER_TYPE_NPC) {}

        NPCType getNPCType() const;


    private:
        NPCType npc_type_;
        
};
