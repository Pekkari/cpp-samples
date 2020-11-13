#include <thread>
#include <chrono>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SFML/display.hpp"

int Display::listen() {
    sf::Vector2f resolution;
    resolution.x = sf::VideoMode::getDesktopMode().width;
    resolution.y = sf::VideoMode::getDesktopMode().height;

    sf::RenderWindow window_(sf::VideoMode(resolution.x, resolution.y),
        "Dungeon Crawler", sf::Style::Fullscreen);

    //Generate input thread
    Input inp;
    std::chrono::microseconds input_processing_time;

    while (window_.isOpen()) {

        // check all the window_'s events that were triggered since the last iteration of the loop
        sf::Event event;

        while (window_.pollEvent(event))
        {
            std::chrono::microseconds processing_time;

            // TODO: Process input

            // "close requested" event: we close the window_
            if (event.type == sf::Event::Closed)
                window_.close();


            // clear the window_ with black color
            window_.clear(sf::Color::Black);

            // Draw scene

            // end the current frame
            window_.display();

            std::this_thread::sleep_for(
                std::chrono::microseconds(std::chrono::microseconds(16) - processing_time)
            );
        }
    }

    window_.close();
    return 0;
}

Display::Display() {
    display_listener_ = std::async(std::launch::async, &Display::listen, this);
}

Display::Display(int (&handler)()) {
    display_listener_ = std::async(std::launch::async, &Display::listen, this);
}

void Display::Close() {
    window_.close();
}
