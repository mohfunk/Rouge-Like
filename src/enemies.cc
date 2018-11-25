#include"characters.hpp"
#include"enemies.hpp"
#include <string>
#include <math.h>
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int row, int colmn, string race, int gold, char prev, char symbol) : Character(hp,atk,def,row,colmn,race,gold,prev,symbol), hasMoved(false) {}
Enemy::~Enemy() {}
void Enemy::setMoved(bool val){
    hasMoved = val;
}
bool Enemy::getMoved() {
    return hasMoved;
}



Human::Human(): Enemy(140, 20, 20, 0, 0, "Human", 0, '.', 'H'){}
Human::~Human(){}



Dwarf::Dwarf(): Enemy(100, 20, 30, 0, 0, "Dwarf", 0, '.', 'W'){}
Dwarf::~Dwarf(){}



Elf::Elf(): Enemy(140, 30, 25, 0, 0, "Elf", 0, '.', 'E'){}
Elf::~Elf(){}



Orc::Orc(): Enemy(180, 30, 25, 0, 0, "Orc", 0, '.', 'O'){}
Orc::~Orc(){}



Merchant::Merchant(): Enemy(30, 70, 5, 0, 0, "Merchant", 0, '.', 'M'){}
Merchant::~Merchant(){}


Dragon::Dragon(int gr, int gc) : Enemy(150, 20, 20, 0, 0, "Dragon", 0, '.', 'D'), GoldRow(gr), GoldCol(gc) {}
int Dragon::getGoldRow() {
    return GoldRow;
}
int Dragon::getGoldCol() {
    return GoldCol;
}
Dragon::~Dragon(){}



Halfling::Halfling(): Enemy(100, 15, 20, 0, 0, "Halfling", 0, '.', 'L'){}
Halfling::~Halfling(){}
