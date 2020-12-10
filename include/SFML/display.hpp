#include <future>
#include <queue>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "SFML/input.hpp"
#include "SFML/texture_loader.hpp"


class Display {
    std::future<int> display_listener_;
    std::queue<InputEvent> input_event_queue_;
    static std::queue<Asset> asset_queue_;
    static std::mutex mtx;
    TextureLoader assets_;

    int listen();
    const sf::Texture& drawScene(sf::RenderTexture& scene);
public:
    Display() { }

    std::future<int> GetListenerThread();
    std::queue<InputEvent>& GetInputEventQueue() { return input_event_queue_; }
    std::queue<Asset>& GetDrawQueue() { return asset_queue_; }
    void draw(const std::string& name,
        sf::Vector2f position = sf::Vector2f(0,0),
        sf::Vector2f scale = sf::Vector2f(0,0),
        bool flip = false
    );
};
