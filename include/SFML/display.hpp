#include <future>
#include <queue>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFML/input.hpp"

class Display {
    std::future<int> display_listener_;
    std::queue<InputEvent> input_event_queue_;

    int listen();
public:
    Display();
    Display(int (&handler)());

    std::future<int> GetListenerThread() { return std::move(display_listener_); }
    std::queue<InputEvent>& GetInputEventQueue() { return input_event_queue_; }
};
