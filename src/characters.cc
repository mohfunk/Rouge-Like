#include "characters.hpp"



#include <string>


using namespace std;
// ctor
Character::Character(int hp, int atk, int def, 
        int r, int c, string Race, 
        int gold, char prv, char sym): HP(hp), Atk(atk), Def(def), row(r), column(c), race(Race), Gold(gold), prev(prv), symbol(sym){}


//dtor
Character::~Character(){}



bool Character::isDead(){
    if(HP == 0){
        return true;
    }
    return false;
}



int Character::getHP(){
    return HP;
}



void Character::setHP(int hp){
    HP = hp;
}



int Character::getDef(){
    return Def;
}



void Character::setDef(int def){
    Def = def;
}



int Character::getAtk(){
    return Atk;
}



void Character::setAtk(int atk){
    Atk = atk;
}



int Character::getRow(){
    return row;
}



void Character::setRow(int Row){
    row = Row;
}



int Character::getCol(){
    return column;
}



void Character::setCol(int col){
    column = col;
}



string Character::getRace(){
    return race;
}



int Character::getGold(){
    return Gold;
}



void Character::setGold(int gold){
    Gold = gold;
}



char Character::getPrev(){
    return prev;
}



void Character::setPrev(char prv){
    prev = prv;
}



char Character::getSymbol(){
    return symbol;
}
