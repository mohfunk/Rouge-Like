#include "../include/characters.hpp"
#include <string>
using namespace std;
// ctor
Character::Character(int hp, int atk, int def, int r, int c, string Race, int gold, char prv, char sym): HP(hp), Atk(atk), Def(def), row(r), column(c), race(Race), Gold(gold), prev(prv), symbol(sym){}
//dtor
Character::~Character(){}
// isDead
bool Character::isDead(){
	if(HP == 0){
		return true;
	}
	return false;
}
 // getHP       
int Character::getHP(){
	return HP;
}
// setHP        
void Character::setHP(int hp){
	HP = hp;
}
// getDef        
int Character::getDef(){
	return Def;
}
// setDef        
void Character::setDef(int def){
	Def = def;
}
// getAtk       
int Character::getAtk(){
	return Atk;
}
// setAtk       
void Character::setAtk(int atk){
	Atk = atk;
}
// getRow
int Character::getRow(){
        return row;
}
// setRow
void Character::setRow(int Row){
        row = Row;
}
// getCol
int Character::getCol(){
        return column;
}
// setCol
void Character::setCol(int col){
        column = col;
}
// getRace
string Character::getRace(){
        return race;
}
// getGold
int Character::getGold(){
        return Gold;
}
// setGold
void Character::setGold(int gold){
        Gold = gold;
}
// getPrev
char Character::getPrev(){
        return prev;
}
// setPrev
void Character::setPrev(char prv){
        prev = prv;
}
// getSymbol
char Character::getSymbol(){
        return symbol;
}
