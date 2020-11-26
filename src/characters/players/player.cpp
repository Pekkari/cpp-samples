#include <iostream>
#include "characters/players/player.hpp"

int Player::getMana() const {
    return mana_;
}

int Player::getSpeed() const {
    return speed_;
}

int Player::getExp() const {
    return exp_;
}

void Player::setMana(int value) {
    mana_ = value;
    if (mana_ > max_mana_) {
        mana_ = max_mana_;
    }
}

void Player::setSpeed(int value) {
    speed_ = value;
    if (speed_ > max_speed_) {
        speed_ = max_speed_;
    }
}

void Player::setExp(int value) {
    exp_ = value;
    if (mana_ > max_exp_) {
        exp_ = max_exp_;
    }
}

void Player::consumeItem(int keyPress) {
    for (auto it = items_.begin(); it != items_.end();) {
        if ((*it)->getType() == ITEM_TYPE_HEALTH_POTION) {
            std::cout << "Player consumed " << (*it)->getType() << " and had HP changed by " << (*it)->getValue() << std::endl;
            hp_ += (*it)->getValue();
            if (hp_ > max_hp_) {
                hp_ = max_hp_;
            }
            it = items_.erase(it);
        }
        else if((*it)->getType() == ITEM_TYPE_MANA_POTION) {
            std::cout << "Player consumed " << (*it)->getType() << " and had Mana changed by " << (*it)->getValue() << std::endl;
            mana_ += (*it)->getValue();
            if (mana_ > max_mana_) {
                mana_ = max_mana_;
            }
            it = items_.erase(it);
        } else if((*it)->getType() == ITEM_TYPE_ARMOR) {
            std::cout << "Player put on new " << (*it)->getType() << " and had ArmorStrength changed by " << (*it)->getValue() << std::endl;
            armor_strength_ += (*it)->getValue();
            if (armor_strength_ > max_armor_strength_) {
                armor_strength_ = max_armor_strength_;
            }
            it = items_.erase(it);
        } else if((*it)->getType() == ITEM_TYPE_BOOTS) {
            std::cout << "Player put on new " << (*it)->getType() << " and had Speed changed by " << (*it)->getValue() << std::endl;
            speed_ += (*it)->getValue();
            if (speed_ > max_speed_) {
                speed_ = max_speed_;
            }
            it = items_.erase(it);
        } else if(((((*it)->getType() == ITEM_TYPE_WOODEN_SWORD) || (*it)->getType() == ITEM_TYPE_IRON_SWORD) || (*it)->getType() == ITEM_TYPE_NANO_SWORD)) {
            std::cout << "Player wielded a new " << (*it)->getType() << " and had Damage they can inflict changed to " << (*it)->getValue() << std::endl;
            damage_ = (*it)->getValue();
            it = items_.erase(it);
       } else {
            it++;
       }
    }
}

void Player::interactNPC(NPC& npc) {

}

CHARACTER_TYPE_t Player::getType() const {
    return CHARACTER_TYPE_PLAYER;
}
