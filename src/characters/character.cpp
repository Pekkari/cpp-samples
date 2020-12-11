#include <chrono>
#include <cstdint>
#include <iostream>
#include "characters/character.hpp"

uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

const std::string& Character::getName() const {
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

void Character::removeItem(ItemType item_type) {
    for (auto it = items_.begin(); it != items_.end(); ++it) {
        if ((*it)->getType() == item_type) {
            it = items_.erase(it);
            break;
        }
    }
}

void Character::addItem(Item* item) {
    items_.emplace_back(std::move(item));
}

// usage, e.g.: player.transferItem(item_type, npc) where player = to, npc = from
bool Character::transferItem(ItemType item_type, Character& from)  {
    for (auto it = from.getItems().begin(); it != from.getItems().end(); ++it) {
        if ((*it)->getType() == item_type) {
            this->addItem(*it);
            from.removeItem(item_type);
            return true;
        }
    }
    return false;
}

uint64_t Character::getLastAttackTime() const {
    return last_attack_time_;
}

void Character::setLastAttackTime() {
    last_attack_time_ = timeSinceEpochMillisec();
}

bool Character::isIdle() {
    if ((timeSinceEpochMillisec() - last_attack_time_) > (uint64_t)1000) {
        return true;
    } else {
        return false;
    }
}

/*
Used in character battles. 
 
Usage: char1.attack(char2). char1 attacks char2, enemy or player or vice versa.

@params this, the attacker
@params Character& character, the attackee
@return returns true if the attackee was killed.
*/
bool Character::attack(Character& character) {
    //std::cout<<"Epochmillsecs: " << timeSinceEpochMillisec() << std::endl;
    //std::cout<<"Last attack time: " << last_attack_time_ << std::endl;
    //std::cout<<"Epoch - Last = " << timeSinceEpochMillisec()- last_attack_time_ << std::endl;
    if (this->getType() == CharacterType::CHARACTER_TYPE_PLAYER || this->isIdle()) {
        // write and do something like: this->animation_swing_sword()
        if (this->getName() != character.getName()) { // attackee and attacker are not the same
            // do also below steps
            int impact = damage_ - character.getArmorStrength();
            if (impact < 0) {
                impact = 0;
            }
            int value = character.getHP() - impact;
            if (value < 0) {
                value = 0;
            }
            character.setHP(value);
        }
        this->setLastAttackTime();
        return !character.isAlive();
    } else {
        // if attacker not idle do not do any animation
        return false;
    }
}

bool Character::isAlive() const {
    if (hp_ < 1) {
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

CharacterType Character::getType() const {
    return char_type_;
}