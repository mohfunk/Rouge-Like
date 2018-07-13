#include "../include/players.hpp"
#include <climits>
using namespace std;


/* PLAYER CLASS */
// ctor
Player::Player(int hp, int atk, int def, int row, int col, string race, int gold, char prev, char sym, int Cham, int MHP): Character(hp,atk,def,row,col,race,gold,prev,sym), cham(Cham), maxHP(MHP){}
// dtor        
Player::~Player(){}
// resetAD
void Player::resetAD(){}
// getMaxHP
int Player::getMaxHP(){
    return maxHP;
}
/* SHADE CLASS */
// ctor
Shade::Shade(): Player(125, 25, 25, 0, 0, "Shade", 0, '.', '@', 0, 125){}
// dtor
Shade::~Shade(){}
// resetAD
void Shade::resetAD(){
    setAtk(25);
    setDef(25);
}
/* DROW CLASS */
// ctor
Drow::Drow(): Player(150, 25, 15, 0, 0, "Drow", 0, '.', '@', 0, 150){}
// dtor
Drow::~Drow(){}
// resetAD
void Drow::resetAD(){
    setAtk(25);
    setDef(15);
}
/* VAMPIRE CALSS */
// ctor
Vampire::Vampire(): Player(50, 25, 25, 0, 0, "Vampire", 0, '.', '@', 0, INT_MAX){}
// dtor
Vampire::~Vampire(){}
// resetAD
void Vampire::resetAD(){
    setAtk(25);
    setDef(25);
}
/* TROLL CLASS */
// ctor
Troll::Troll(): Player(120, 25, 15, 0, 0, "Troll", 0, '.', '@', 0, 120){}
// dtor
Troll::~Troll(){}
// resetAD
void Troll::resetAD(){
    setAtk(25);
    setDef(15);
}
/* GOBLIN CLASS */
// ctor
Goblin::Goblin(): Player(110, 15, 20, 0, 0, "Goblin", 0, '.', '@', 0, 110){}
// dtor
Goblin::~Goblin(){}
// resetAD
void Goblin::resetAD(){
    setAtk(15);
    setDef(20);
}
