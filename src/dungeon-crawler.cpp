#include "SFML/display.hpp"

int main(void) {
    Display dis;

    std::future<int> display_listener = dis.GetListenerThread();
    display_listener.get();

    return 0;
}
