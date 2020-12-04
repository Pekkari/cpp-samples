#include <fstream>
#include <sstream>
#include <string>

#include "game/chamber.hpp"


Chamber::Chamber(std::vector<std::vector<GameTile*>> tiles, std::vector<Enemy*> enemies, std::vector<NPC*> npcs, sf::Vector2f entrance,
        sf::Vector2f exit)
            : tiles_(tiles), enemies_(enemies), npcs_(npcs), entrancePos_(entrance), exitPos_(exit){
    //TODO necessary components
    setInitialSate();
}

Chamber::~Chamber(){
    for ( auto it : enemies_){
        delete it;
    }
    for ( auto it : npcs_){
        delete it;
    }
    for ( auto it : tiles_){
        for ( auto i : it){
            delete i;
        }
    }
}
//TODO pass gameTiles and characters to display
void Chamber::setInitialSate(){

}
