#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "game/game.hpp"

int main(void) {
    Game game;

    while(game.running()){
        std::chrono::microseconds processing_time;

        game.handleInput();

        std::this_thread::sleep_for(
            std::chrono::microseconds(std::chrono::milliseconds(1) - processing_time)
        );
    }
    //game.display_listener.get();
    return 0;
}
