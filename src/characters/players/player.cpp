#include <iostream>
#include "characters/players/player.hpp"

void Player::pickupItem(Item* item) {
    items_.push_back(item);
}

void Player::consumeItem(int keyPress) {
    for (auto it = items_.begin(); it != items_.end();) {
        if (keyPress == 1 && it->getName() == "hp") {
            std::cout << "Player consumed " << it->getName() << " and had HP changed by " << it->getValue() << std::endl;
            hp_ += it->getValue();
            if (hp_ > max_hp_) {
                hp_ = max_hp_;
            }
            it = items_.erase(it);
        } else if (keyPress == 2 && it->getName() == "mana") {
            std::cout << "Player consumed " << it->getName() << " and had Mana changed by " << it->getValue() << std::endl;
            mana_ += it->getValue();
            if (mana_ > max_mana_) {
                mana_ = max_mana_;
            }
            it = items_.erase(it);
        } else if (keyPress == 3 && it->getName() == "armor") {
            std::cout << "Player put on new " << it->getName() << " and had ArmorStrength changed by " << it->getValue() << std::endl;
            armor_strength_ += it->getValue();
            if (armor_strength_ > max_armor_strength_) {
                armor_strength_ = max_armor_strength_;
            }
            it = items_.erase(it);
        } else if (keyPress == 4 && it->getName() == "boots") {
            std::cout << "Player put on new " << it->getName() << " and had Speed changed by " << it->getValue() << std::endl;
            speed_ += it->getValue();
            if (speed_ > max_speed_) {
                speed_ = max_speed_;
            }
            it = items_.erase(it);
        } else if (keyPress == 5 && it->getName() == "sword") {
            std::cout << "Player wielded a new " << it->getName() << " and had Damage they can inflict changed to " << it->getValue() << std::endl;
            damage_ = it->getValue();
            it = items_.erase(it);
       } else {
            it++;
       }
    }
}

int Player::getHP() const {
    return hp_;
}

int Player::getMana() const {
    return mana_;
}

int Player::getArmorStrength() const {
    return armor_strength_;
}

int Player::getSpeed() const {
    return speed_;
}

int Player::getDamage() const {
    return damage_;
}

int Player::getExp() const {
    return exp_;
}

void Player::deliverAttack(Enemy& enemy) {
    // enemy.absorbAttack(Player& this);
    int impact = damage_ - enemy.armor_strength_;
    if (impact < 0) {
        impact = 0;
    }
    enemy.hp_ = enemy.hp_ - impact;
}

void Player::absorbAttack(Enemy& enemy) {
    int impact = enemy.damage_ - armor_strength_;
    if (impact < 0) {
        impact = 0;
    }
    hp_ = hp_ - impact;
}

void Player::interactNPC(NPC& npc) {

}

bool Player::isAlive() const {
    if (hp_ <= 0) {
        return false;
    } else {
        return true;
    }
}
