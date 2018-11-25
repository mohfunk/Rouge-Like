#include"potionstrategy.hpp"
#include"potion.hpp"
#include"players.hpp"
#include<string>
using namespace std;

PotionStrategy::PotionStrategy(){}

PotionStrategy::~PotionStrategy(){}

RHStrategy::RHStrategy(): PotionStrategy(){}

RHStrategy::~RHStrategy(){}

void RHStrategy::usePotion(Player &player){
    if((player.getHP() + 10) > player.getMaxHP()){
        player.setHP(player.getMaxHP());
    }
    else{	
        if(player.getRace() == "Drow"){
            if((player.getHP() + 15) > player.getMaxHP()){
                player.setHP(player.getMaxHP());
            }
            else{
                player.setHP(player.getHP() + 15);
            }
        }
        else{
            player.setHP(player.getHP() + 10);
        }
    }
}

string RHStrategy::getName(){
    return "RH";
}

BAStrategy::BAStrategy(): PotionStrategy(){}

BAStrategy::~BAStrategy(){}

void BAStrategy::usePotion(Player &player){
    if(player.getRace() == "Drow"){
        player.setAtk(player.getAtk() + 7);
    }
    else{
        player.setAtk(player.getAtk() + 5);
    }
}

string BAStrategy::getName(){
    return "BA";
}

BDStrategy::BDStrategy(): PotionStrategy(){}

BDStrategy::~BDStrategy(){}

void BDStrategy::usePotion(Player &player){
    if(player.getRace() == "Drow"){
        player.setDef(player.getDef() + 7);
    }
    else{
        player.setDef(player.getDef() + 5);
    }
}

string BDStrategy::getName(){
    return "BD";
}


PHStrategy::PHStrategy(): PotionStrategy(){}

PHStrategy::~PHStrategy(){}

void PHStrategy::usePotion(Player &player){
    if((player.getHP() - 10) < 0){
        player.setHP(0);
    }
    else{
        if(player.getRace() == "Drow"){
            if((player.getHP() - 15) < 0){
                player.setHP(0);
            }
            else{
                player.setHP(player.getHP() - 15);
            }
        }
        else{
            player.setHP(player.getHP() - 10);
        }
    }
}

string PHStrategy::getName(){
    return "PH";
}

WAStrategy::WAStrategy(): PotionStrategy(){}

WAStrategy::~WAStrategy(){}

void WAStrategy::usePotion(Player &player){
    if((player.getAtk() - 5 < 0 || (player.getRace() == "Drow" && player.getAtk() - 7 < 0))){
        player.setAtk(0);
    }
    else if(player.getRace() == "Drow"){
        player.setAtk(player.getAtk() - 7);
    }
    else{
        player.setAtk(player.getAtk() - 5);
    }
}

string WAStrategy::getName(){
    return "WA";
}

WDStrategy::WDStrategy(): PotionStrategy(){}

WDStrategy::~WDStrategy(){}

void WDStrategy::usePotion(Player &player){
    if((player.getDef() - 5) < 0 || (player.getRace() == "Drow" && player.getDef() - 7 < 0)){
        player.setDef(0);
    }
    else if(player.getRace() == "Drow"){
        player.setDef(player.getDef() - 7);
    }
    else{
        player.setDef(player.getDef() - 5);
    }
}

string WDStrategy::getName(){
    return "WD";
}

