#include "characters/character.hpp"

class Enemy : public Character {


    public:

        Enemy(std::string& name, sf::Vector2<float> position, int hp, int damage) // sf::Vector2<float> = sf::Vector2f
            : hp_(hp), damage_(damage), active_(false), Character(name, position) {}
        
        int getHP() const;
        bool setHP(int hp);

        int getDamage() const;
        bool setDamage(int damage);



    private:

        int hp_;
        int damage_;
        bool active_;
};
