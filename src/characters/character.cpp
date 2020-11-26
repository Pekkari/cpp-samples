// Character is an abstract class
// This file contains methods of it

#include "characters/character.hpp"

#include <chrono>
#include <cstdint>
#include <iostream>

uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

std::string Character::getName() const {
    return name_;
}

sf::Vector2<float> Character::getPosition() const {
    return position_;
}

int Character::getHP() const {
    return hp_;
}

int Character::getDamage() const {
    return damage_;
}

int Character::getArmorStrength() const {
    return armor_strength_;
}

void Character::setHP(int value) {
    hp_ = value;
    if (hp_ > max_hp_) {
        hp_ = max_hp_;
    }
}

void Character::setDamage(int value) {
    damage_ = value;
    if (damage_ > max_damage_) {
        damage_ = max_damage_;
    }
}

void Character::setArmorStrength(int value) {
    armor_strength_ = value;
    if (armor_strength_ > max_armor_strength_) {
        armor_strength_ = max_armor_strength_;
    }
}

std::vector<Item*> Character::getItems() const {
    return items_;
}

// some compile problem here so I commented the lines out
void Character::removeItem(ITEM_TYPE_t item_type) {
// Item& Character::removeItem(ITEM_TYPE_t item_type) {
/*
    for (auto it = items_.begin(); it != items_.end();) {
        if (it->getType() == item_type) {
            Item& item = it;
            it = items_.erase(it);
        }
        it++;
    }
    return new Item*;
*/
}

void Character::addItem(Item* item) {
    items_.emplace_back(item);
}

uint64_t Character::getLastAttackTime() const {
    return last_attack_time_;
}

void Character::setLastAttackTime() {
    last_attack_time_ = timeSinceEpochMillisec();
}

bool Character::isIdle() {
    if (timeSinceEpochMillisec() - last_attack_time_ > 200) {
        return true;
    } else {
        return false;
    }
}



/*
 * Usage: char1.attack(char2)
 * => char1 attacks char2, enemy or player or vice versa.
 * returns true if the attack was successful, i.e. the actor was at idle state.
 */
bool Character::attack(Character& character) {
    if (this->isIdle()) {
        int impact = damage_ - character.getArmorStrength();
        if (impact < 0) {
            impact = 0;
        }
        int value = character.getHP() - impact;
        if (value < 0) {
            value = 0;
        }
        character.setHP(value);
        if (value == 0) {
            std::cout << name_ << " has killed " << character.getName() << std::endl;
           if (char_type_ == CHARACTER_TYPE_ENEMY) {
                std::cout << name_ << " had exp points " << exp_ << std::endl;
                exp_++;
                std::cout << "and now exp points have been raised to " << exp_ << std::endl;
            }
        }
        this->setLastAttackTime();
        return true;
    } else {
        return false;
    }
}

bool Character::isAlive() const {
    if (hp_ == 0) {
        return false;
    } else {
        return true;
    }
}

void Character::move(sf::Vector2<float> new_position) {
    position_ = new_position;
}

// This will be SFML method that renders the item
void Character::Draw() const {

}
