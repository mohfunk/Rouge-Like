#include"../include/gold.hpp"
#include<string>
using namespace std;

// ctor
Gold::Gold(string tp): Item(), type(tp), isTied(false){
	if(tp == "small pile"){
		value = 1;
		deadDragon = true;
	}
	else if(tp == "normal pile"){
                value = 2;
		deadDragon = true;
        }
	else if(tp == "merchant hoard"){
                value = 4;
		deadDragon = true;
        }
	else if(tp == "Dragon hoard"){
		value = 6;
		deadDragon = false;
	}
	else{
		value = 4;
		deadDragon = true;
	}
}



// dtor
Gold::~Gold(){}



// DragonIsDEad
void Gold::DragonIsDead(){
	deadDragon = true;
}



// cantake
bool Gold::canTake(){
        return deadDragon;
}



// getvalue
int Gold::getValue(){
	return value;
}
 


// getType       
string Gold::getType(){
	return type;
}



// setIsTied
void Gold::setIsTied(bool val) {
		isTied = val;
}



// getIsTied
bool Gold::getIsTied() {
	return isTied;
}
