#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "game/game.hpp"

int main(void) {
    Game game;
    sf::Vector2f position(400, 300);
    sf::Vector2f scale(5, 5);
    std::string filename("elf_f_idle_anim_f0.png");
    bool flip = true;

    while(game.running()){
        std::chrono::milliseconds processing_time;

        game.display_->draw(filename, position, scale, flip);
        game.handleInput();
        game.update();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(std::chrono::milliseconds(1000) - processing_time)
        );
    }
    game.display_listener.get();

    return 0;
}
