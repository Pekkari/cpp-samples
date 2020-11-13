#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include "SFML/display.hpp"

int main(void) {
    Display dis;

    std::future<int> display_listener = dis.GetListenerThread();
    std::queue<InputEvent>& events = dis.GetInputEventQueue();

    while (true) {
        std::chrono::microseconds processing_time;
        if (!events.empty()) {
            std::string input_event_name = events.front().GetName();
            std::cout << "Input event: " << input_event_name << std::endl;
            if (input_event_name == "KeyEsc") {
                std::cout << "Quitting" << std::endl;
                break;
            }
            events.pop();
        }
        std::this_thread::sleep_for(
            std::chrono::microseconds(std::chrono::milliseconds(1) - processing_time)
        );
    }

    display_listener.get();
    return 0;
}
