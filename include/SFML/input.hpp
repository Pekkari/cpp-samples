#include <queue>

#include "SFML/input_event.hpp"

class Input {
    std::queue<InputEvent> actions_;

public:
    Input() { }
    Input(void (&handler)()) { }

    InputEvent listen();
};
