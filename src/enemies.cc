#include "characters.h"
#include "enemies.h"
#include <string>
#include <math.h>
using namespace std;

/* ENEMY CLASS */
// ctor Enemy
Enemy::Enemy(int hp, int atk, int def, int row, int colmn, string race, int gold, char prev, char symbol) : Character(hp,atk,def,row,colmn,race,gold,prev,symbol), hasMoved(false) {}
// dtor Enemy
Enemy::~Enemy() {}
// setMoved
void Enemy::setMoved(bool val){
        hasMoved = val;
}
// getMoved
bool Enemy::getMoved() {
	return hasMoved;
}



/* HUMAN CLASS */
// ctor
Human::Human(): Enemy(140, 20, 20, 0, 0, "Human", 0, '.', 'H'){}
// dtor
Human::~Human(){}



/* DWARF CLASS */
// ctor
Dwarf::Dwarf(): Enemy(100, 20, 30, 0, 0, "Dwarf", 0, '.', 'W'){}
// dtor
Dwarf::~Dwarf(){}



/* ELF CLASS */
// ctor
Elf::Elf(): Enemy(140, 30, 25, 0, 0, "Elf", 0, '.', 'E'){}
// dtor
Elf::~Elf(){}



/* ORC CLASS */
// ctor
Orc::Orc(): Enemy(180, 30, 25, 0, 0, "Orc", 0, '.', 'O'){}
// dtor
Orc::~Orc(){}



/* MERCHANT CLASS */
// ctor
Merchant::Merchant(): Enemy(30, 70, 5, 0, 0, "Merchant", 0, '.', 'M'){}
// dtor
Merchant::~Merchant(){}



/* DRAGON CLASS */
Dragon::Dragon(int gr, int gc) : Enemy(150, 20, 20, 0, 0, "Dragon", 0, '.', 'D'), GoldRow(gr), GoldCol(gc) {}
// getGoldRow
int Dragon::getGoldRow() {
	return GoldRow;
}
// getGoldCol
int Dragon::getGoldCol() {
	return GoldCol;
}
// dtor
Dragon::~Dragon(){}



/* HALFLING CLASS */
// ctor
Halfling::Halfling(): Enemy(100, 15, 20, 0, 0, "Halfling", 0, '.', 'L'){}
// dtor
Halfling::~Halfling(){}
