#include <queue>
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

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
        "Dungeon Crawler", sf::Style::Fullscreen);

    //Generate input processor
    Input inp;

    sf::Event event;
    while (window.isOpen()) {
        std::chrono::microseconds processing_time;

        while (window.pollEvent(event)) {

            // Process input
            if (event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::MouseButtonPressed) {
                InputEvent input_ev = inp.listen();
                input_event_queue_.push(input_ev);

                // Check Esc keypress to close window
                if (input_ev.GetName() == "KeyEsc")
                    window.close();
            }

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // Draw scene

            // end the current frame
            window.display();
        }
        std::this_thread::sleep_for(
            std::chrono::microseconds(std::chrono::microseconds(16) - processing_time)
        );
    }

    return 0;
}

Display::Display() {
    display_listener_ = std::async(std::launch::async, &Display::listen, this);
}

Display::Display(int (&handler)()) {
    display_listener_ = std::async(std::launch::async, handler);
}
