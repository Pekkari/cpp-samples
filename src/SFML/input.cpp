#include <iostream>
#include <queue>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "SFML/input.hpp"

std::queue<InputEvent> Input::listen() {
    std::queue<InputEvent> event_queue;

    // Handle keyboard events
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        std::cout << "Moving left" << std::endl;
        event_queue.push(InputEvent("KeyA"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        std::cout << "Moving right" << std::endl;
        event_queue.push(InputEvent("KeyD"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        std::cout << "Moving up" << std::endl;
        event_queue.push(InputEvent("KeyW"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        std::cout << "Moving down" << std::endl;
        event_queue.push(InputEvent("KeyS"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        std::cout << "General action" << std::endl;
        event_queue.push(InputEvent("KeyE"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        std::cout << "Quitting" << std::endl;
        event_queue.push(InputEvent("KeyEsc"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        std::cout << "Special skill 1" << std::endl;
        event_queue.push(InputEvent("Key1"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        std::cout << "Special skill 2" << std::endl;
        event_queue.push(InputEvent("Key2"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        std::cout << "Special skill 3" << std::endl;
        event_queue.push(InputEvent("Key3"));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    {
        std::cout << "Special skill 4" << std::endl;
        event_queue.push(InputEvent("Key4"));
    }

    // Handle mouse events
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        std::cout << "Attack!" << std::endl;
        event_queue.push(InputEvent("MouseLeft"));
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        std::cout << "Drinking!" << std::endl;
        event_queue.push(InputEvent("MouseRight"));
    }

    return event_queue;
}
