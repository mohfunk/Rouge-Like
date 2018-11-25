#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include"floor.hpp"
#include"characters.hpp"
#include"players.hpp"
#include"game.hpp"
#include"potion.hpp"
#include"enemies.hpp"
using namespace std;
// checkHelp
void Floor::checkHelp(int row,int col){
	for(int i = 0; i < countp;i++){
		if((potion[i]->getRow() == row) && (potion[i]->getCol() == col)){
			if(potion[i]->getView()){
				action += "The PC sees a " + potion[i]->getName() + " potion ";
			}
			else{
				action += "The PC sees an unknown potion ";
			} // else
		} // if
	} // for
} // checkHelp


// checkForP
void Floor::checkForP(){
	if(td->floor[player->getRow() + 1][player->getCol()] == 'P'){
		checkHelp(player->getRow() + 1, player->getCol());
		action += "to the south. ";
	}
	if(td->floor[player->getRow() - 1][player->getCol()] == 'P'){
		checkHelp(player->getRow() - 1, player->getCol());
		action += "to the north. ";
	}
	if(td->floor[player->getRow()][player->getCol() + 1] == 'P'){
		checkHelp(player->getRow(), player->getCol() + 1);
		action += "to the east. ";
	}
	if(td->floor[player->getRow()][player->getCol() - 1] == 'P'){
		checkHelp(player->getRow(), player->getCol() - 1);
		action += "to the west. ";       
	}
	if(td->floor[player->getRow() + 1][player->getCol() + 1] == 'P'){
		checkHelp(player->getRow() + 1, player->getCol() + 1);
		action += "to the southeast. ";      
	}
	if(td->floor[player->getRow() + 1][player->getCol() - 1] == 'P'){
		checkHelp(player->getRow() + 1, player->getCol() - 1);  
		action += "to the southwest. "; 
	}
	if(td->floor[player->getRow() - 1][player->getCol() + 1] == 'P'){
		checkHelp(player->getRow() - 1, player->getCol() + 1);   
		action += "to the northeast. "; 
	}
	if(td->floor[player->getRow() - 1][player->getCol() - 1] == 'P'){
		checkHelp(player->getRow() - 1, player->getCol() - 1);
		action += "to the northwest. ";   
	} // if
} // checkForP

// getCell
char Floor::getCell(int r,int c){
	return td->floor[r][c];
}
// getFloornum
int Floor::getFloornum(){
	return floornum;
}

/*
	for reference
   |-----------------------------------------------------------------------------|
   |                                                                             |
   | |--------------------------|        |-----------------------|               |
   | |..........................|        |.......................|               |
   | |..........................+########+.......................|-------|       |
   | |..........................|   #    |...............................|--|    |
   | |..........................|   #    |..................................|--| |
   | |----------+---------------|   #    |----+----------------|...............| |
   |            #                 #############                |...............| |
   |            #                 #     |-----+------|         |...............| |
   |            #                 #     |............|         |...............| |
   |            ###################     |............|   ######+...............| |
   |            #                 #     |............|   #     |...............| |
   |            #                 #     |-----+------|   #     |--------+------| |
   |  |---------+-----------|     #           #          #              #        |
   |  |.....................|     #           #          #         |----+------| |
   |  |.....................|     ########################         |...........| |
   |  |.....................|     #           #                    |...........| |
   |  |.....................|     #    |------+--------------------|...........| |
   |  |.....................|     #    |.......................................| |
   |  |.....................+##########+.......................................| |
   |  |.....................|          |.......................................| |
   |  |---------------------|          |---------------------------------------| |
   |                                                                             |
   |-----------------------------------------------------------------------------|

 */

// chamber
int Floor::chamber(int cham){
	int ran = game->random(5);
	if(ran == cham){
		return chamber(cham);
	}
	return ran;
}

// row
int Floor::row(int cham){
	if(cham == 0){
		return 3 + game->random(4);
	}
	else if(cham == 1){
		return 3 + game->random(10);
	}
	else if(cham == 2){
		return 10 + game->random(3);
	}
	else if(cham == 3){
		return 15 + game->random(7);
	}
	else{
		return 16 + game->random(6);
	}
}
// col
int Floor::Col(int cham, int row){
	int col;
	if(cham == 0){
		col = 3 + game->random(26);
		if(isValid(row,col)){
			return col;
		}
		else{
			return Col(cham, row);
		}
	}
	else if(cham == 1){
		if(row == 3 || row == 4){
			col = 39 + game->random(23);
		}
		else if(row == 5){
			col = 39 + game->random(31);
		}
		else if(row == 6){
			col = 39 + game->random(34);
		}
		else{
			col = 61 + game->random(15);
		}
		if(isValid(row,col)){
			return col;
		}
		else{
			return Col(cham, row);
		}
	}
	else if(cham == 2){
		col = 38 + game->random(12);
		if(isValid(row,col)){
			return col;
		}
		else{
			return Col(cham, row);
		}
	}
	else if(cham == 3){
		col = 4 + game->random(21);
		if(isValid(row,col)){
			return col;
		}
		else{
			return Col(cham, row);
		}
	}
	else{
		if(row == 16 || row == 17 || row == 18){
			col = 65 + game->random(11);
		}
		else{
			col = 37 + game->random(39);
		}
		if(isValid(row,col)){
			return col;
		}
		else{
			return Col(cham, row);
		}
	}
}

// isValid
bool Floor::isValid(int row, int col){
	if(td->floor[row][col] == '.' || td->floor[row][col] == '+' || td->floor[row][col] == '#'){
		return true;
	}
	else{
		return false;
	}
}


// ctor
Floor::Floor(Player &Player, Game &gm, string file): player(&Player), action(""), floornum(1), game(&gm), RH(false), BA(false), BD(false), PH(false), WA(false), WD(false), HostilM(false){
	td = new TextDisplay;
	reset(file);
}
// setDragon
void Floor::setDragon(Dragon & d, int r, int c){
	int ran = game->random(8);
	if(canMove(r,c) == false){
		return;
	}
	if(ran == 0 && isDot(r - 1, c)){
		d.setRow(r - 1);
		d.setCol(c);
		td->floor[r-1][c] = 'D';
	}
	else if(ran == 1 && isDot(r, c + 1)){
		d.setRow(r);
		d.setCol(c + 1);
		td->floor[r][c+1] = 'D';
	}
	else if(ran == 2 && isDot(r + 1, c)){
		d.setRow(r + 1);
		d.setCol(c);
		td->floor[r+1][c] = 'D';
	}
	else if(ran == 3 && isDot(r, c-1)){
		d.setRow(r);
		d.setCol(c-1);
		td->floor[r][c-1] = 'D';
	}
	else if(ran == 4 && isDot(r - 1, c + 1)){
		d.setRow(r - 1);
		d.setCol(c + 1);
		td->floor[r-1][c + 1] = 'D';
	}
	else if(ran == 5 && isDot(r + 1, c + 1)){
		d.setRow(r + 1);
		d.setCol(c + 1);
		td->floor[r+1][c+1] = 'D';
	}
	else if(ran == 0 && isDot(r + 1, c -1)){
		d.setRow(r + 1);
		d.setCol(c-1);
		td->floor[r+1][c-1] = 'D';
	}
	else if(ran == 0 && isDot(r - 1, c - 1)){
		d.setRow(r - 1);
		d.setCol(c -1);
		td->floor[r-1][c-1] = 'D';
	}
	else{
		setDragon(d, r, c);
	}
}

void Floor::reset(string file){
	// creation and set up of potions, gold, enemies, and dragon arrays
	potion = new Potion*[10];
	gold = new Gold*[10];
	enemy = new Enemy*[20];
	dragon = new Dragon*[10];
	for(int i = 0; i < 10;i++){ // setting dragons to null
		dragon[i] = NULL;
	}
	if(file == ""){ // handles command line gameplay ( when no files is given )
		// initial set up
		countp = 10;
		countg = 10;
		counte = 20;
		countd = 10; 
		cape = 20;
		capp = 10;
		capg = 10;
		capd = 10;
		int cham;
		int pcham = chamber();
		int Row = row(pcham);
		int col = Col(pcham, Row);
		player->setRow(Row);
		player->setCol(col);
		player->setPrev('.');
		td->floor[Row][col] = '@';
		cham = chamber(pcham);
		Row = row(cham);
		col = Col(cham, Row);
		td->floor[Row][col] = '\\';
		// potions creation and placement
		for(int i = 0; i < 10;i++){   
			// creation
			int ran = game->random(6);
			if(game->Probability(1,ran)){
				potion[i] = new Potion(new RHStrategy);
				if(RH){
					potion[i]->viewTrue();
				}
			}
			else if(game->Probability(2,ran)){
				potion[i] = new Potion(new BAStrategy);
				if(BA){
					potion[i]->viewTrue();
				}
			}
			else if(game->Probability(3,ran)){
				potion[i] = new Potion(new BDStrategy);
				if(BD){
					potion[i]->viewTrue();
				}
			}
			else if(game->Probability(4,ran)){
				potion[i] = new Potion(new PHStrategy);
				if(PH){
					potion[i]->viewTrue();
				}
			}
			else if(game->Probability(5,ran)){
				potion[i] = new Potion(new WAStrategy);
				if(WA){
					potion[i]->viewTrue();
				}
			}
			else{
				potion[i] = new Potion(new WDStrategy);
				if(WD){
					potion[i]->viewTrue();
				}
			}
			// placement
			cham = chamber();
			Row = row(cham);
			col = Col(cham, Row);
			potion[i]->setRow(Row);
			potion[i]->setCol(col);
			td->floor[Row][col] = 'P';
		} // for loop
		/*
		cham = chamber();
		Row = row(cham);
		col = Col(cham, Row);
		*/
		// gold creation and placement
		for(int i = 0; i < 10;i++){
			// creation
			int ran = game->random(8);
			if(game->Probability(0,ran)){
				gold[i] = new Gold("Dragon hoard");
			}
			else if(game->Probability(1,ran) || game->Probability(2,ran)){
				gold[i] = new Gold("small pile"); 
			}
			else {
				gold[i] = new Gold("normal pile");
			}
			// placement
			cham = chamber();
			Row = row(cham);
			col = Col(cham, Row);
			gold[i]->setRow(Row);
			gold[i]->setCol(col);
			if(ran == 0){
				for(int j = 0;j < 10;j++){ // dragons creation, placement and tying to dragon hords
					if(dragon[j] == NULL){
						dragon[j] = new Dragon(gold[i]->getRow(), gold[i]->getCol());						
						setDragon(*dragon[j], gold[i]->getRow(), gold[i]->getCol());
						break;
					} // if
				} // for
			} // if
			td->floor[Row][col] = 'G';
		} // for loop
		// enemies creation and replacement
		for(int i = 0; i < 20;i++){
                        int ran = game->random(18);
                        if(game->Probability(0,ran) || game->Probability(1,ran) || game->Probability(2,ran) || game->Probability(3,ran)) {
                                enemy[i] = new Human;
                        }
                        else if(game->Probability(4,ran) || game->Probability(5,ran) || game->Probability(6,ran)) {
                                enemy[i] = new Dwarf;
                        }
                        else if(game->Probability(7,ran) || game->Probability(8,ran) || game->Probability(9,ran) || game->Probability(10,ran) || game->Probability(11,ran) ) {
                                enemy[i] = new Halfling;
                        }
                        else if(game->Probability(12,ran) || game->Probability(13,ran) ) {
                                enemy[i] = new Elf;
                        }
                        else if(game->Probability(14,ran) || game->Probability(15,ran) ) {
                                enemy[i] = new Orc;
                        }
                        else {
                                enemy[i] = new Merchant;
                        } // if 
                        cham = chamber();
                        Row = row(cham);
                        col = Col(cham,Row);
                        enemy[i]->setRow(Row);
                        enemy[i]->setCol(col);
                        td->floor[Row][col] = enemy[i]->getSymbol();
                } // for

	}
	else{  // reading in from a file
		countp = 0;
		countg = 0;
		counte = 0;
		countd = 0;
		cape = 20;
		capp = 10;
		capg = 10;
		capd = 10;
		ifstream ifs(file.c_str());
		for(int i = 1; i < floornum; i++){
			for(int j = 0; j < 25;j++){ // numof floors
				string s;
				getline(ifs,s);
			}
		}
		for(int i = 0; i < 25; i++){
			string s;
			getline(ifs,s);
			for(int j = 0; j < 79; j++){
				if(capp == countp){
					capp *= 2;
					Potion **newp;
					newp = new Potion*[capp];
					for(int i = 0;i < countp;i++){
						newp[i] = potion[i];
					}
					delete []potion;
					potion = newp;
				}
				if(capg == countg){
					capg *= 2;
					Gold **newg;
					newg = new Gold*[capg];
					for(int i = 0;i < countg;i++){
						newg[i] = gold[i];
					}
					delete []gold;
					gold = newg;
				}
				if(cape == counte){
					cape *= 2;
					Enemy **newe;
					newe = new Enemy*[cape];
					for(int i = 0;i < counte;i++){
						newe[i] = enemy[i];
					}
					delete []enemy;
					enemy = newe;
				}
				if(capd == countd){
                                        capd *= 2;
                                        Dragon **newd;
                                        newd = new Dragon*[capd];
                                        for(int i = 0;i < countd;i++){
                                                newd[i] = dragon[i];
                                        }
                                        delete []dragon;
                                        dragon = newd;
                                }	
				if(s[j] == '@'){
					player->setRow(i);
					player->setCol(j);
					td->floor[i][j] = '@';
				}
				else if(s[j] == '0'){
					potion[countp] = new Potion(new RHStrategy);
					potion[countp]->setRow(i);
					potion[countp]->setCol(j);
					if(RH){
						potion[countp]->viewTrue();
					}
					countp += 1;
					td->floor[i][j] = 'P';
				}
				else if(s[j] == '1'){
					potion[countp] = new Potion(new BAStrategy);
					potion[countp]->setRow(i);
					potion[countp]->setCol(j);
					if(BA){
						potion[countp]->viewTrue();
					}
					countp += 1;
					td->floor[i][j] = 'P';
				}
				else if(s[j] == '2'){
					potion[countp] = new Potion(new BDStrategy);
					potion[countp]->setRow(i);
					potion[countp]->setCol(j);
					if(BD){
						potion[countp]->viewTrue();
					}
					countp += 1;
					td->floor[i][j] = 'P';
				}
				else if(s[j] == '3'){
					potion[countp] = new Potion(new PHStrategy);
					potion[countp]->setRow(i);
					potion[countp]->setCol(j);
					if(PH){
						potion[countp]->viewTrue();
					}
					countp += 1;
					td->floor[i][j] = 'P';
				}
				else if(s[j] == '4'){
					potion[countp] = new Potion(new WAStrategy);
					potion[countp]->setRow(i);
					potion[countp]->setCol(j);
					if(WA){
						potion[countp]->viewTrue();
					}
					countp += 1;
					td->floor[i][j] = 'P';
				}
				else if(s[j] == '5'){
					potion[countp] = new Potion(new WDStrategy);
					potion[countp]->setRow(i);
					potion[countp]->setCol(j);
					if(WD){
						potion[countp]->viewTrue();
					}
					countp += 1;
					td->floor[i][j] = 'P';
				}
				else if(s[j] == '6'){
					gold[countg] = new Gold("normal pile");
					gold[countg]->setRow(i);
					gold[countg]->setCol(j);
					countg += 1;
					td->floor[i][j] = 'G';
				}
				else if(s[j] == '7'){
					gold[countg] = new Gold("small pile");
					gold[countg]->setRow(i);
					gold[countg]->setCol(j);
					countg += 1;
					td->floor[i][j] = 'G';
				}
				else if(s[j] == '8'){
					gold[countg] = new Gold("merchant hoard");
					gold[countg]->setRow(i);
					gold[countg]->setCol(j);
					countg += 1;
					td->floor[i][j] = 'G';
				}
				else if(s[j] == '9'){
					gold[countg] = new Gold("Dragon hoard");
					gold[countg]->setRow(i);
					gold[countg]->setCol(j);
					countg += 1;
					td->floor[i][j] = 'G';
				}
				else if(s[j] == 'H'){
					enemy[counte] = new Human;
                                        enemy[counte]->setRow(i);
                                        enemy[counte]->setCol(j);
                                        counte += 1;
                                        td->floor[i][j] = 'H';
				}
				else if(s[j] == 'W'){
                                        enemy[counte] = new Dwarf;
                                        enemy[counte]->setRow(i);
                                        enemy[counte]->setCol(j);
                                        counte += 1;
                                        td->floor[i][j] = 'W';
                                }
				else if(s[j] == 'E'){
                                        enemy[counte] = new Elf;
                                        enemy[counte]->setRow(i);
                                        enemy[counte]->setCol(j);
                                        counte += 1;
                                        td->floor[i][j] = 'E';
                                }
				else if(s[j] == 'O'){
                                        enemy[counte] = new Orc;
                                        enemy[counte]->setRow(i);
                                        enemy[counte]->setCol(j);
                                        counte += 1;
                                        td->floor[i][j] = 'O';
                                }
				else if(s[j] == 'M'){
                                        enemy[counte] = new Merchant;
                                        enemy[counte]->setRow(i);
                                        enemy[counte]->setCol(j);
                                        counte += 1;
                                        td->floor[i][j] = 'M';
                                }
				else if(s[j] == 'L'){
                                        enemy[counte] = new Halfling;
                                        enemy[counte]->setRow(i);
                                        enemy[counte]->setCol(j);
                                        counte += 1;
                                        td->floor[i][j] = 'L';
                                }
				else{
                                        td->floor[i][j] = s[j];
                                }// else
			}// for j
		}// for i
		// read again, look for dragons and tie them with their dragon hords
		for(int i = 0; i < 25; i++){
                        for(int j = 0; j < 79; j++){
				if(capd == countd){
                                        capd *= 2;
                                        Dragon **newd;
                                        newd = new Dragon*[capd];
                                        for(int i = 0;i < countd;i++){
                                                newd[i] = dragon[i];
                                        }
                                        delete []dragon;
                                        dragon = newd;
                                }
				if(td->floor[i][j] == 'D'){
					int r;
					int c;
					for(int g = 0; g < countg; g++){
						r = gold[g]->getRow();
                                                c = gold[g]->getCol();
						if(gold[g]->getType() == "Dragon hoard" && gold[g]->getIsTied() == false && isOneRad(r,c,i,j)){
							dragon[countd] = new Dragon(r,c);
                                        		dragon[countd]->setRow(i);
                                        		dragon[countd]->setCol(j);
                                        		countd += 1;
							gold[g]->setIsTied(true);
							break;
						} // if
					} // for counting gold
                                } // if
			} // for j
		} // for i
	} // else ( reading from files)
} // reset



// isOneRad
bool Floor::isOneRad(int r1, int c1, int r2, int c2){
        int r = r1 - r2;
	int c = c1 - c2;
	if( r == -1 && c == 0 ) {return true;}
        else if( r == 0 && c == 1 ) {return true;}
        else if(  r == 1 && c == 0  ) {return true;}
        else if(  r == 0 && c == -1 ) {return true;}
        else if(  r == -1 && c == -1  ) {return true;}
        else if(  r == -1 && c == 1  ) {return true;}
        else if(  r == 1 && c == 1 ) {return true;}
        else if(  r == 1 && c == -1 ) {return true;}
        else {return false;}
}



// dtor
Floor::~Floor(){
	delete td;
	for(int i = 0; i < countp; i++){
		delete potion[i];
	}
	for(int i = 0; i < countg; i++){
		delete gold[i];
	}
	for(int i = 0; i < counte; i++){
		delete enemy[i];
	}
	for(int i = 0; i < countd; i++){
		delete dragon[i];
	}
	delete[] enemy;
	delete[] potion;
	delete[] gold;
	delete[] dragon;
}


// printFloor
void Floor::printFloor(){
	td->print();
	cout << "Race: " << player->getRace();
	cout << " Gold: " << player->getGold();
	cout << "                                                  Floor " << floornum << endl;
	cout << "HP: " << player->getHP() << endl;
	cout << "Atk: " << player->getAtk() << endl;
	cout << "Def: " << player->getDef() << endl;
	cout << "Action: " << action << endl;
}
// setAction
void Floor::setAction(string desc){
	action = desc;
}
// setPoint
void Floor::setPoint(int row, int col, Player &player, string file){
	if(isValid(row, col)){
		if (td->floor[player.getRow()][player.getCol()] == '|' || td->floor[player.getRow()][player.getCol()] == '-'){
			player.setPrev('.');
			player.setRow(row);
			player.setCol(col);
			td->floor[row][col] = player.getSymbol();
		}
		else{
			td->floor[player.getRow()][player.getCol()] = player.getPrev();
			player.setPrev(td->floor[row][col]);
			player.setRow(row);
			player.setCol(col);
			td->floor[row][col] = player.getSymbol();
		}
	} // if
	else if(td->floor[row][col] == '\\'){
		floornum += 1;
		if(floornum == 6){
			cout << "You have conquered the dungeon." << endl;
			if(player.getRace() == "Shade"){
				cout << "Score: " << (player.getGold() * 1.5)  << endl;
			}
			else{
				cout << "Score: " << player.getGold()  << endl;
			}
			return;
		}
		for(int i = 0; i < countp; i++){
			delete potion[i];
		}
		delete[] potion;
		for(int i = 0; i < countg; i++){
			delete gold[i];
		}
		delete[] gold;
		for(int i = 0; i < counte; i++){
			delete enemy[i];
		}
		delete[] enemy;
		for(int i = 0; i < countd; i++){
			delete dragon[i];
		}
		delete[] dragon;
		action += "Player ascends to another floor and the effects of attack and defence potions have been lifted. ";
		player.setPrev('.');
		player.resetAD();
		td->reset();
		reset(file);
	} // else if
	else if(td->floor[row][col] == 'G'){
		td->floor[player.getRow()][player.getCol()] = player.getPrev();
		player.setPrev('.');
		for(int i = 0; i < countg; i++){
			if(gold[i]->getRow() == row && gold[i]->getCol() == col){
				if(gold[i]->getType() == "Dragon hoard"){
					if(isDragonNear(gold[i]->getRow(),gold[i]->getCol()) == false){
						gold[i]->DragonIsDead();
					}
				}
				if(gold[i]->canTake()){
					player.setGold(player.getGold() + gold[i]->getValue());
					stringstream ss;
					ss << gold[i]->getValue();
					string s;
					ss >> s;
					if(gold[i]->getType() == "2 normal piles"){
						action += "Player picks up " + gold[i]->getType() + " of gold (" + s + "). ";
					}
					else{
						action += "Player picks up a " + gold[i]->getType() + " of gold (" + s + "). ";
					}
					break;
				}
				else{
					player.setPrev('G');
					action += "Can't take gold until the Dragon is slain. ";
					break;
				} // else
			} // if
		} // for
		player.setRow(row);
		player.setCol(col);
		td->floor[row][col] = player.getSymbol();
	} // else if
} // setPoint
// isDragonNear
bool Floor::isDragonNear(int r, int c){
	if( td->floor[r-1][c] == 'D' ) {return true;}
	else if( td->floor[r][c+1] == 'D' ) {return true;}
	else if( td->floor[r+1][c] == 'D' ) {return true;}   
	else if( td->floor[r][c-1] == 'D' ) {return true;}
	else if( td->floor[r-1][c+1] == 'D' ) {return true;}   
	else if( td->floor[r-1][c-1] == 'D' ) {return true;}
	else if( td->floor[r+1][c+1] == 'D' ) {return true;}   
	else if( td->floor[r+1][c-1] == 'D' ) {return true;}
	else {return false;}
}
// usePotion
void Floor::usePotion(int r, int c){
	for(int i = 0;i < countp;i++){
		if(r == potion[i]->getRow() && c == potion[i]->getCol()){
			action += "PC consumes a " + potion[i]->getName() + " potion. ";
			potion[i]->usePotion(*player);
			td->floor[potion[i]->getRow()][potion[i]->getCol()] = '.';
			if(potion[i]->getName() == "RH" && RH == false){
				RH = true;
				setPotionsTrue("RH");
			}
			else if(potion[i]->getName() == "BA" && BA == false){
				BA = true;
				setPotionsTrue("BA");
			}
			else if(potion[i]->getName() == "BD" && BD == false){
				BD = true;
				setPotionsTrue("BD");
			}
			else if(potion[i]->getName() == "PH" && PH == false){
				PH = true;
				setPotionsTrue("PH");
			}
			else if(potion[i]->getName() == "WA" && WA == false){
				WA = true;
				setPotionsTrue("WA");
			}
			else if(potion[i]->getName() == "WD" && WD == false){
				WD = true;
				setPotionsTrue("WD");
			} //else if
		} //if
	} // for
} // usePotion



// setPotionsTrue
void Floor::setPotionsTrue(string name){
	for(int i = 0; i < countp; i ++){
		if(potion[i]->getName() == name){
			potion[i]->viewTrue();
		} // if
	} // for
} // setPotionsTrue




// isDot
bool Floor::isDot(int row, int col) {
	if(td->floor[row][col] == '.') { return true;}
	return false;
}



// nearByPlayer
bool Floor::nearByPlayer(int row, int col) {
	if(td->floor[row-1][col] == '@') {return true;} // north
	if(td->floor[row][col+1] == '@') {return true;} // east
	if(td->floor[row+1][col] == '@') {return true;} // south
	if(td->floor[row][col-1] == '@') {return true;} // west
	if(td->floor[row-1][col+1] == '@') {return true;} // ne
	if(td->floor[row+1][col+1] == '@') {return true;} // se
	if(td->floor[row+1][col-1] == '@') {return true;} // sw
	if(td->floor[row-1][col-1] == '@') {return true;} // nw
	else { return false; }
}





// canMove
bool Floor::canMove(int row, int col) {
	if(td->floor[row-1][col] == '.') {return true;} // north
	if(td->floor[row][col+1] == '.') {return true;} // east
	if(td->floor[row+1][col] == '.') {return true;} // south
	if(td->floor[row][col-1] == '.') {return true;} // west
	if(td->floor[row-1][col+1] == '.') {return true;} // ne
	if(td->floor[row+1][col+1] == '.') {return true;} // se
	if(td->floor[row+1][col-1] == '.') {return true;} // sw
	if(td->floor[row-1][col-1] == '.') {return true;} // nw
	else { return false; }
}





// MoveEnemy
void Floor::MoveEnemy(Enemy & e) {
	int ran = game->random(8);
	int r = e.getRow();
	int c = e.getCol();
	if ( ran == 0 ) {
		if(isDot(r-1,c)) {
			e.setRow(r-1);
			td->floor[r][c] = '.';
			td->floor[r-1][c] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 1 ) {
		if(isDot(r,c+1)) {
			e.setCol(c+1);
			td->floor[r][c] = '.';
			td->floor[r][c+1] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 2 ) {
		if(isDot(r+1,c)) {
			e.setRow(r+1);
			td->floor[r][c] = '.';
			td->floor[r+1][c] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 3 ) {
		if(isDot(r,c-1)) {
			e.setCol(c-1);
			td->floor[r][c] = '.';
			td->floor[r][c-1] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 4 ) {
		if(isDot(r-1,c+1)) {
			e.setRow(r-1);
			e.setCol(c+1);
			td->floor[r][c] = '.';
			td->floor[r-1][c+1] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 5 ) {
		if(isDot(r+1,c+1)) {
			e.setRow(r+1);
			e.setCol(c+1);
			td->floor[r][c] = '.';
			td->floor[r+1][c+1] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 6 ) {
		if(isDot(r+1,c-1)) {
			e.setRow(r+1);
			e.setCol(c-1);
			td->floor[r][c] = '.';
			td->floor[r+1][c-1] = e.getSymbol();
		} else {
			MoveEnemy(e);
		}
	}
	else if ( ran == 7 ) {
		if(isDot(r-1,c-1)) {
			e.setRow(r-1);
			e.setCol(c-1);
			td->floor[r][c] = '.';
			td->floor[r-1][c-1] = e.getSymbol();
		} else {
			MoveEnemy(e);
		} // else
	} // else if
 } // moveEnemy



// Enemybeh
void Floor::Enemybeh() {
	for(int j = 0;j < 25;j++) {
		for(int k = 0; k < 79; k++) {
			if(td->floor[j][k] == 'D') { // dragon attacks
				for(int l = 0; l < countd; ++l) {
					if(dragon[l] != NULL){
						if(dragon[l]->getRow() == j && dragon[l]->getCol() == k) {
							if(nearByPlayer(j,k) || nearByPlayer(dragon[l]->getGoldRow(), dragon[l]->getGoldCol())){
								EnemyAtk(*dragon[l]);
							} // if player nearby
						} // if dragon at
					} // if dragon
				} // for
			} // if dragon
			// other enemies
			else if(td->floor[j][k] == 'H' || td->floor[j][k] == 'W' || td->floor[j][k] == 'E' || td->floor[j][k] == 'O' || td->floor[j][k] == 'M' || td->floor[j][k] == 'L'){
				for(int i = 0; i <  counte; i++){
					int r = enemy[i]->getRow();
					int c = enemy[i]->getCol();
					if(r == j && c == k && enemy[i]->getMoved() == false){
						if (nearByPlayer(r,c) == false && canMove(r,c) && enemy[i]->isDead() == false) {
							MoveEnemy(*enemy[i]);
							enemy[i]->setMoved(true);
						}		
						else if (nearByPlayer(r,c) && enemy[i]->isDead() == false) {
							EnemyAtk(*enemy[i]);
						} // else if
					} // if
				} // for
			} // else if
		} // for k
	} // for j
	// after attacking, enemies cant move
	for(int g = 0; g < counte;g++){
		enemy[g]->setMoved(false);
	}
}	
// EnemyAtk
void Floor::EnemyAtk(Enemy & e){
	if(e.getSymbol() == 'M'){
		if(HostilM){
			if(game->random(2) == 0){
				int health = player->getHP();
				string s;
				game->PlayerDamage(*player, e);
				health = health - player->getHP();
				stringstream ss;
				ss << health;
				ss >> s;
				action += "The " + e.getRace() + " dealt " + s + " damage to the player. ";
			}
			else{
				action += "The " + e.getRace() + "'s attack missed. ";
			}
		}
	}
	else if(e.getSymbol() == 'E'){
		if(player->getRace() == "Drow"){
			if(game->random(2) == 0){
				int health = player->getHP();
				string s;
				game->PlayerDamage(*player, e);
				health = health - player->getHP();
				stringstream ss;
				ss << health;
				ss >> s;
				action += "The " + e.getRace() + " dealt " + s + " damage to the player. ";
			}
			else{
				action += "The " + e.getRace() + "'s attack missed. ";
			}
		}
		else{
			if(game->random(2) == 0){
				int health = player->getHP();
				string s;
				game->PlayerDamage(*player, e);
				health = health - player->getHP();
				stringstream ss;
				ss << health;
				ss >> s;
				action += "The " + e.getRace() + "'s first attack dealt " + s + " damage to the player. ";
			}
			else{
				action += "The Elf's first attack missed. ";
			}
			if(game->random(2) == 0){
				int health = player->getHP();
				string s;
				game->PlayerDamage(*player, e);
				health = health - player->getHP();
				stringstream ss;
				ss << health;
				ss >> s;
				action += "The " + e.getRace() + "'s second attack dealt " + s + " damage to the player. ";
			}
			else{
				action += "The Elf's second attack missed. ";
			}

		}
	}	
	else if(game->random(2) == 0){
		int health = player->getHP();
		string s;
		game->PlayerDamage(*player, e);
		health = health - player->getHP();
		stringstream ss;
		ss << health;
		ss >> s;
		action += "The " + e.getRace() + " dealt " + s + " damage to the player. ";
	}
	else{
		action += "The " + e.getRace() + "'s attack missed. ";
	}
}


void Floor::PlayerAtk(int r,int c){
	for(int i = 0; i < countd; i++){
		if(dragon[i] != NULL) {
			if(dragon[i]->getRow() == r && dragon[i]->getCol() == c){
				int health = dragon[i]->getHP();
				game->EnemyDamage(*player, *dragon[i]);
				health = health - dragon[i]->getHP();
				if(dragon[i]->isDead()){
					action += "The PC has slain the dragon. ";
					int rw = dragon[i]->getGoldRow();
					int cl = dragon[i]->getGoldCol();
					for(int j = 0; j < countg;j++){
						if(gold[j]->getRow() == rw && gold[j]->getCol() == cl){
							gold[j]->DragonIsDead();
							break;
						}
					}
					td->floor[dragon[i]->getRow()][dragon[i]->getCol()] = '.';
				}
				else{
					string s;
					string h;
					stringstream ss;
					ss << health;
					ss >> s;
					stringstream sss;
					sss << dragon[i]->getHP();
					sss >> h;
					action += "The PC dealt " + s + " damage to the dragon (" + h + "). ";
				} // else
			} // if
		} // if
	} // for
	for(int i = 0; i < counte;i++){
		if(enemy[i]->getRow() == r && enemy[i]->getCol() == c){
			int health = enemy[i]->getHP();
			if(enemy[i]->getSymbol() == 'L'){
				int ran = game->random(2);
				if(ran == 1){
					action += "The halfling dodged your attack. ";
					break;
				}
			}
			if(enemy[i]->getSymbol() == 'M'){
				if(HostilM == false){
					HostilM = true;
					action += "You attack a merchant. Now all merchants will attack you if you go near them. ";
				}
			}
			game->EnemyDamage(*player, *enemy[i]);
			if(player->getRace() == "Vampire"){
				if(enemy[i]->getSymbol() == 'W'){
					if(player->getHP() - 5 < 0){
						player->setHP(0);
						action += "PC died from bad blood. "; 
					}
					else{
						player->setHP(player->getHP() - 5);
						action += "Vampires are allergic to dwarfs. The PC loses 5 HP. ";
					}
				}
				else{
					player->setHP(player->getHP() + 5);
					action += "Vampire drank some blood and restored 5 hp. ";
				}
			}
			if(enemy[i]->isDead()){
				td->floor[enemy[i]->getRow()][enemy[i]->getCol()] = '.';
				action += "The PC has slain the " + enemy[i]->getRace() + ". ";
				if(enemy[i]->getSymbol() == 'H'){
					if(capg == countg){
						capg *= 2;
						Gold **newg;
						newg = new Gold*[capg];
						for(int j = 0;j < countg;j++){
							newg[j] = gold[j];
						}
						delete []gold;
						gold = newg;
					}
					gold[countg] = new Gold("2 normal piles");
					gold[countg]->setRow(enemy[i]->getRow());
					gold[countg]->setCol(enemy[i]->getCol());
					td->floor[enemy[i]->getRow()][enemy[i]->getCol()] = 'G';
					countg += 1;
				}
				else if(enemy[i]->getSymbol() == 'M'){
					if(capg == countg){
						capg *= 2;
						Gold **newg;
						newg = new Gold*[capg];
						for(int j = 0;j < countg;j++){
							newg[j] = gold[j];
						}
						delete []gold;
						gold = newg;
					}
					gold[countg] = new Gold("merchant hoard");
					gold[countg]->setRow(enemy[i]->getRow());
					gold[countg]->setCol(enemy[i]->getCol());
					td->floor[enemy[i]->getRow()][enemy[i]->getCol()] = 'G';
					countg += 1;
				}
				else if(enemy[i]->getSymbol() != 'D'){
					int ran = game->random(2);
					if(ran == 0){
						player->setGold(player->getGold() + 2);
						action += "PC recieves 2 gold for killing the " + enemy[i]->getRace() + ". ";
					}
					else{
						player->setGold(player->getGold() + 1);
						action += "PC recieves 1 gold for killing the " + enemy[i]->getRace() + ". ";
					}
				}
				if(player->getRace() == "Goblin"){
					player->setGold(player->getGold() + 5);
					action += " PC steals 5 gold from the " + enemy[i]->getRace() + ". ";
				}
			}
			else {
				health = health - enemy[i]->getHP();
				string s;
				string h;
				stringstream ss;
				ss << health;
				ss >> s;
				stringstream sss;
				sss << enemy[i]->getHP();
				sss >> h;
				action += "The PC dealt " + s + " damage to the " + enemy[i]->getRace() + " (" + h + "). ";
			} // else
			break;
		} // if
	} // for
} //player atk






// notifiy
void Floor::notify(int row, int col, string input, string file) {
	action = "";		// start with an empty action
	bool b = true;		// to stop enemies from moving while going up the stairs
	if (td->floor[row+player->getRow()][col+player->getCol()] == '\\') { b = false; }
	if(player->getRace() == "Troll" && player->getMaxHP() != player->getHP()){
		if(player->getHP() + 5 > player->getMaxHP()){
			player->setHP(player->getMaxHP());
			action += "The player is back at full health. ";
		}
		else{
			player->setHP(player->getHP() + 5);
			action += "5 HP has been restored to the player. ";
		}
	}
	if ( input == "no" ) action += "PC moves North. ";
	if ( input == "so" ) action += "PC moves South. ";
	if ( input == "ea" ) action += "PC moves East. ";
	if ( input == "we" ) action += "PC moves West. ";
	if ( input == "ne" ) action += "PC moves NorthEast. ";
	if ( input == "nw" ) action += "PC moves NorthWest. ";
	if ( input == "se" ) action += "PC moves SouthEast. ";
	if ( input == "sw" ) action += "PC moves SouthWest. ";
	if ( input[0] == 'u' ){
		usePotion(row + player->getRow(),col + player->getCol());
	}
	else if(input[0] == 'a'){
		PlayerAtk(row + player->getRow(),col + player->getCol());
	}
	else{
		setPoint(row + player->getRow(),col + player->getCol(), *this->player, file);
		if(floornum == 6) return;
	}
	checkForP();
	if ( b == true) {
		Enemybeh();
	}
	printFloor();
}
