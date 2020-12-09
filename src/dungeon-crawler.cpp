#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "game/game.hpp"

int main(void) {
    Game game;

    while(game.running()){
        std::chrono::milliseconds processing_time;

        game.handleInput();
        game.update();
        game.render();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(std::chrono::milliseconds(1000) - processing_time)
        );
    }
    game.display_listener.get();

    return 0;
}
