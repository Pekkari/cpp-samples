#include <iostream>
#include <queue>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "SFML/input.hpp"

InputEvent Input::listen() {

    // Handle keyboard events
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        return InputEvent(InputType::KeyA);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return InputEvent(InputType::KeyD);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        return InputEvent(InputType::KeyW);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return InputEvent(InputType::KeyS);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        return InputEvent(InputType::KeyE);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        return InputEvent(InputType::KeyR);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return InputEvent(InputType::KeyEsc);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return InputEvent(InputType::KeySpace);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        return InputEvent(InputType::Key1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        return InputEvent(InputType::Key2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        return InputEvent(InputType::Key3);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        return InputEvent(InputType::Key4);

    // Handle mouse events
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        return InputEvent(InputType::MouseLeft);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        return InputEvent(InputType::MouseRight);

    return InputEvent();
}
