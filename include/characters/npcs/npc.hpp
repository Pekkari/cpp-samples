#pragma once

#include <string>
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "characters/character.hpp"

class NPC : public Character {


    public:


        NPC(std::string& name, sf::Vector2<float> position)
            : Character(name, position) {}
        
    
   


        // Get and set positions, move
        sf::Vector2<float> getPosition() const;
        bool setPosition(sf::Vector2<float> newPosition);

        // Get and set name
        std::string getName() const;
        bool setName(const std::string& name);

        

        // Handling items, see below
        // std::vector<Item*> getItemList() const;
        // bool addItem(Item* item);
        // Item* popItem(std::string itemName); // Also ITEM_TYPE may be used, tbd
        



    private:
        sf::Vector2<float> position_;
        // Not yet defined how the NPCs are keeping the items they are supposed to give.
        //std::vector<Item*> items_; placeholder for Item class objects the NPC might have

        
};
