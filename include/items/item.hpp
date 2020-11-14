#include <string>
#include <SFML/System/Vector2.hpp>

//Every item has a type
typedef enum
{
    ITEM_TYPE_WOODEN_SWORD,
    ITEM_TYPE_IRON_SWORD,
    ITEM_TYPE_NANO_SWORD,
    ITEM_TYPE_ARMOR,
    ITEM_TYPE_BOOTS,
    ITEM_TYPE_KEY,
    ITEM_TYPE_MANA_POTION,
    ITEM_TYPE_HEALTH_POTION
} ITEM_TYPE_t;

class Item {
public:
    Item(std::string& name, sf::Vector2<float> position) :
        name_(name), position_(position) {}
    virtual ~Item() {};
    std::string getName() const;
    sf::Vector2<float> getPosition() const;
    virtual ITEM_TYPE_t getType() const = 0;
    virtual void Draw() const = 0; //This will be SFML method that renders the item
private:
    std::string name_;
    sf::Vector2<float> position_;
    ITEM_TYPE_t type_;
};
