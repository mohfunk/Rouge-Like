#include"item.h"
using namespace std;
// ctor
Item::Item(): row(0), col(0){}



// dtor
Item::~Item(){}


// getRow
int Item::getRow(){
	return row;
}



// getCol
int Item::getCol(){
	return col;
}


// setRow
void Item::setRow(int r){
	row = r;
}



// setCol       
void Item::setCol(int c){
	col = c;
}
