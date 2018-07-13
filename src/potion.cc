#include"potion.h"
#include"potionstrategy.h"
#include<string>
using namespace std;



// ctor
Potion::Potion(PotionStrategy *PS): Item(), ps(PS){
	view = false;	
}



// dtor
Potion::~Potion(){ 
	delete ps;
}


// usePotion
void Potion::usePotion(Player &player){
	view = true;
	ps->usePotion(player);
}



// getName
string Potion::getName(){
	return ps->getName();
}	



// getView
bool Potion::getView(){
	return view;
}


// viewTrue
void Potion::viewTrue(){
	view = true;	// we just set it to true, we dont need to set it to false whatsoever
}
