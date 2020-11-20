#include <iostream>
#include <queue>
#include <mutex>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SFML/display.hpp"

#define MAX_DRAWING_ELEMENTS 6000
#define WINDOW_STYLE sf::Style::Default
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

std::queue<Draw> Display::asset_queue_;

std::mutex Display::mtx;

int Display::listen() {
    sf::Vector2f resolution;
    //resolution.x = sf::VideoMode::getDesktopMode().width;
    //resolution.y = sf::VideoMode::getDesktopMode().height;
    resolution.x = WINDOW_WIDTH;
    resolution.y = WINDOW_HEIGHT;

    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
        "Dungeon Crawler", WINDOW_STYLE);

    //Generate input processor
    Input inp;

    sf::Event event;
    while (window.isOpen()) {
        std::chrono::milliseconds processing_time;

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

        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // Draw scene
        while(!mtx.try_lock());
        while(!asset_queue_.empty()) {
            Draw d = asset_queue_.front();
            Asset asset = assets_.getAsset(d.GetName());
            window.draw(asset.getSprite(d));
            asset_queue_.pop();
        }
        mtx.unlock();

        // end the current frame
        window.display();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(std::chrono::milliseconds(15) - processing_time)
        );
    }

    return 0;
}

std::future<int> Display::GetListenerThread() {
    return std::move(std::async(std::launch::async, &Display::listen, this));
}

void Display::draw(std::string& file, sf::Vector2f position,
    sf::Vector2f scale, bool flip) {
    if (mtx.try_lock()) {
        Draw d(file, position, scale, flip);

        //to much draw request, discard
        if(asset_queue_.size() > MAX_DRAWING_ELEMENTS)
            asset_queue_.pop();
        asset_queue_.push(d);

        mtx.unlock();
    }
}
