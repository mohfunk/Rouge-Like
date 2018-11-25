#include <math.h>
#include <cstdlib>
#include "game.hpp"
#include "characters.hpp"


// ctor
Game::Game(){}


// dtor
Game::~Game(){}


// random
int Game::random(int range){
    return rand() % range;
}


// EnemyDamage
void Game::EnemyDamage(Player &player, Character &enemy){
    int d = (ceil((double)100/(100 + enemy.getDef()) * player.getAtk())); // damage formula
    if((enemy.getHP() - d) < 0){
        enemy.setHP(0);
    }
    else{
        enemy.setHP(enemy.getHP() - d);
    }
}


// PlayerDamage
void Game::PlayerDamage(Player &player, Character &enemy){
    int d =(ceil((double)100/(100 + player.getDef()) * enemy.getAtk())); // damage formula
    if(enemy.getSymbol() == 'O' && player.getRace() == "Goblin"){
        d *= 1.5;
    }
    if((player.getHP() - d) < 0){
        player.setHP(0);
    }
    else{
        player.setHP(player.getHP() - d);
    }
}




// probability
bool Game::Probability(int percent, int ran){
    if(percent == ran){
        return true;
    }
    else{
        return false;
    }
}

