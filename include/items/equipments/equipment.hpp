//Equipment is an abstract class
//This file contains definitions of it
//and all its sub-classes

#include <string>
#include <SFML/System/Vector2.hpp>
#include "items/item.hpp"

class Equipment : public Item {
public:
    Equipment(std::string& name, sf::Vector2<float> position) :
        Item(name, position) {}
    virtual ~Equipment() {};
    virtual ITEM_TYPE_t getType() const = 0;
    virtual void Draw() const = 0; //This will be SFML method that renders the item
private:
};

class Armor : public Equipment{
public:
    Armor(std::string& name, sf::Vector2<float> position);
    virtual ~Armor() {};
    int getStrength() const;
    virtual ITEM_TYPE_t getType() const;
    virtual void Draw() const; //This will be SFML method that renders the item
private:
    int armor_strength_;
    const int ARMOR_START_VALUE = 50;
};

class Boots : public Equipment{
public:
    Boots(std::string& name, sf::Vector2<float> position);
    virtual ~Boots() {};
    int getSpeed() const;
    virtual ITEM_TYPE_t getType() const;
    virtual void Draw() const; //This will be SFML method that renders the item
private:
    int speed_;
    const int SPEED_START_VALUE = 50;
};

//Weapon is an abstract class
class Weapon : public Equipment{
public:
    Weapon(std::string& name, sf::Vector2<float> position) :
        Equipment(name, position) {}
    virtual ~Weapon() {};
    virtual ITEM_TYPE_t getType() const = 0;
    virtual void Draw() const = 0; //This will be SFML method that renders the item
private:
};

class WoodenSword : public Weapon{
public:
    WoodenSword(std::string& name, sf::Vector2<float> position);
    virtual ~WoodenSword() {};
    int getDamage() const;
    virtual ITEM_TYPE_t getType() const;
    virtual void Draw() const; //This will be SFML method that renders the item
private:
    int damage_;
    const int DAMAGE_START_VALUE = 50;
};

class IronSword : public Weapon{
public:
    IronSword(std::string& name, sf::Vector2<float> position);
    virtual ~IronSword() {};
    int getDamage() const;
    virtual ITEM_TYPE_t getType() const;
    virtual void Draw() const; //This will be SFML method that renders the item
private:
    int damage_;
    const int DAMAGE_START_VALUE = 100;
};

class NanoSword : public Weapon{
public:
    NanoSword(std::string& name, sf::Vector2<float> position);
    virtual ~NanoSword() {};
    int getDamage() const;
    virtual ITEM_TYPE_t getType() const;
    virtual void Draw() const; //This will be SFML method that renders the item
private:
    int damage_;
    const int DAMAGE_START_VALUE = 200;
};
