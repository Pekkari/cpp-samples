#include <iostream>
#include <queue>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "SFML/input.hpp"

InputEvent Input::listen() {

    // Handle keyboard events
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return InputEvent("KeyA");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return InputEvent("KeyD");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        return InputEvent("KeyW");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return InputEvent("KeyS");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        return InputEvent("KeyE");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return InputEvent("KeyEsc");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        return InputEvent("Key1");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        return InputEvent("Key2");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        return InputEvent("Key3");
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        return InputEvent("Key4");

    // Handle mouse events
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        return InputEvent("MouseLeft");
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        return InputEvent("MouseRight");

}
