#include "player.hpp"


    const uint_t Player::getHealth(){
        return health;
    }
    const uint_t Player::getDamage(){
        return damage;
    }
    
    void Player::receivedDamage(Player p){
        const uint_t dmg = p.getDamage();
        if(health>dmg){
            health = health - dmg;
        }else if(dmg>=health)
        {
            health=0;
        }
          
    }
    const std::string Player::getName(){
        return name;
    }

