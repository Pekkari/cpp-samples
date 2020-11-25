#include <fstream>
#include <sstream>
#include <string>

#include "game/chamber.hpp"


Chamber::Chamber(std::vector<std::vector<GameTile*>> tiles)
    : tiles_(tiles){
    //TODO necessary components
    setInitialSate();
}

Chamber::~Chamber(){
    for ( auto it : tiles_){
        for ( auto i : it){
            delete i;
        }
    }

}
//TODO pass gameTiles and characters to display
void Chamber::setInitialSate(){

}
