#include<string>
#include<iostream>

#include"controller.hpp"
#include"game.hpp"
#include"players.hpp"
#include"characters.hpp"
#include"floor.hpp"

using namespace std;


// ctor
Controller::Controller() {
    this->game = new Game();
    this->floor = NULL;
    this->player = NULL;
}


// dtor
Controller::~Controller() {
    delete game;
    delete floor;
    delete player;
}



// notifiy notfies the floor class
void Controller::notify(int row, int col, string input, string file) {
    if((input[0] == 'a' || input[0] == 'u') || 	// makes sure you dont move invalidly.
            (floor->getCell(player->getRow() + row, player->getCol() + col) == '.' || 
             floor->getCell(player->getRow() + row, player->getCol() + col) == '\\' || 
             floor->getCell(player->getRow() + row, player->getCol() + col) == '+' || 
             floor->getCell(player->getRow() + row, player->getCol() + col) == '#' || 
             floor->getCell(player->getRow() + row, player->getCol() + col) == 'G')){
        floor->notify(row, col, input, file);
    }
    else{
        floor->setAction("Invalid movement. A wall, monster, or potion blocks your path.");
        floor->printFloor();
    } // else
} // notify


// play
void Controller::play(string file) {			// main game loop.
    char p;
    TextDisplay temp;				// just to print the empty floor at the begining.
    while(true){
        temp.print();
        cout << "Welcome to CC3k." << endl;
        cout << "Please choose one of:" << endl;
        cout << "s for Shade (125 HP, 25 Atk, 25 Def)" << endl;
        cout << "d for Drow (150 HP, 25 Atk, 15 Def) "; 
        cout << "all potions have their effects magnified by 1.5";  
        cout << endl;
        cout << "v for Vampire (50 HP, 25 Atk, 25 Def) "; 
        cout << "gains 5 HP every successful attack and has no maximum HP";
        cout << endl;
        cout << "g for Goblin (110 HP, 15 Atk, 20 Def) "; 
        cout << "steals 5 gold from every slain enemy";
        cout << endl;
        cout << "t for Troll (120 HP, 25 Atk, 15 Def) "; 
        cout << "regains 5 HP every turn";
        cout << endl;
        cout << "All characters except vampires have max hp which is their starting HP" << endl;
        // setting up the player race
        cin >> p;
        if ( p == 's' ) { 
            this->player = new Shade; 
            break;
        }
        else if ( p == 'd' ) { 
            this->player = new Drow; 
            break;
        }
        else if ( p == 'v' ) { 
            this->player = new Vampire; 
            break;
        }
        else if ( p == 'g' ) { 
            this->player = new Goblin; 
            break;
        }
        else if ( p == 't' ) { 
            this->player = new Troll; 
            break;
        }
        // quit and restart commands
        else if (p == 'q'){
            cout << "Quitting game." << endl;
            return;
        }
        else if (p == 'r'){
            cout << "Restarting game." << endl;
        }
        else{ // handles bad input
            cout << "Unfortunately, " << p << " is not a playable character." << endl;
            cout << "Please try again" << endl;
        } // else
    } // while
    string input;
    delete floor; 	// if a floor exists, delete it.
    // initilazing the floor and setting it up
    this->floor = new Floor(*this->player, *this->game, file);
    this->floor->setAction("Player has spawned.");
    this->floor->printFloor();
    while(getline(cin, input)) { // handles input; movement commands, attacking, using potions, quitting and restarting.
        if ( input == "q" ){
            cout << "Quitting game." << endl;
            return;
        }
        if ( input == "r" ) break;
        if ( input == "no" ) notify(-1,0, input, file);
        if ( input == "so" ) notify(1,0, input, file);
        if ( input == "ea" ) notify(0,1, input, file);
        if ( input == "we" ) notify(0,-1, input, file);
        if ( input == "ne" ) notify(-1,1, input, file);
        if ( input == "nw" ) notify(-1,-1, input, file);
        if ( input == "se" ) notify(1,1, input, file);
        if ( input == "sw" ) notify(1,-1, input, file);
        if ( input[0] == 'u' ){
            if(input == "u <no>"){
                if(floor->getCell(player->getRow() - 1,player->getCol()) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();	
                }
                else{
                    notify(-1,0, input, file);
                }
            }
            if(input == "u <so>"){
                if(floor->getCell(player->getRow() + 1,player->getCol()) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(1,0, input, file);
                }
            }
            if(input == "u <ea>"){
                if(floor->getCell(player->getRow(),player->getCol() + 1) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(0,1, input, file);
                }
            }
            if(input == "u <we>"){
                if(floor->getCell(player->getRow(),player->getCol() - 1) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(0,-1, input, file);
                }
            }
            if(input == "u <ne>"){
                if(floor->getCell(player->getRow() - 1,player->getCol() + 1) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(-1,1, input, file);
                }
            }
            if(input == "u <nw>"){
                if(floor->getCell(player->getRow() - 1,player->getCol() - 1) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(-1,-1, input, file);
                }
            }
            if(input == "u <se>"){
                if(floor->getCell(player->getRow() + 1,player->getCol() + 1) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(1,1, input, file);
                }
            }
            if(input == "u <sw>"){
                if(floor->getCell(player->getRow() + 1,player->getCol() - 1) != 'P'){
                    floor->setAction("You can't use that.");
                    floor->printFloor();
                }
                else{
                    notify(1,-1, input, file);
                } // else
            } // if u <sw>
        } // if use
        if ( input[0] == 'a' ){
            if(input == "a <no>"){
                if(!isEnemy(player->getRow() - 1,player->getCol())){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(-1,0, input, file);
                }
            }
            if(input == "a <so>"){
                if(!isEnemy(player->getRow() + 1,player->getCol())){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(1,0, input, file);
                }
            }
            if(input == "a <ea>"){
                if(!isEnemy(player->getRow(),player->getCol() + 1)){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(0,1, input, file);
                }
            }
            if(input == "a <we>"){
                if(!isEnemy(player->getRow(),player->getCol() - 1)){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(0,-1, input, file);
                }
            }
            if(input == "a <ne>"){
                if(!isEnemy(player->getRow() - 1,player->getCol() + 1)){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(-1,1, input, file);
                }
            }
            if(input == "a <nw>"){
                if(!isEnemy(player->getRow() - 1,player->getCol() - 1)){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(-1,-1, input, file);
                }
            }
            if(input == "a <se>"){
                if(!isEnemy(player->getRow() + 1,player->getCol() + 1)){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(1,1, input, file);
                }
            }
            if(input == "a <sw>"){
                if(!isEnemy(player->getRow() + 1,player->getCol() - 1)){
                    floor->setAction("You can't attack that.");
                    floor->printFloor();
                }
                else{
                    notify(1,-1, input, file);
                } // else
            } // if a <sw>
        } // if attack
        if(player->isDead()){ // break if the player died
            break;		
        }
        if (floor->getFloornum() == 6) break; // break if the player won
    } // while loop
    // handles death
    if(player->isDead()){
        cout << "You have died." << endl;
        if(player->getRace() == "Shade"){
            cout << "Score: " << player->getGold() * 1.5 << endl;
        }
        else{
            cout << "Score: " << player->getGold() << endl;
        }
        cout << "Enter r to start a new game or q to quit." << endl;
        while(cin >> input){
            if(input == "r"){
                delete player;
                player = NULL;
                cout << "Restarting game."  << endl;
                play(file);
                return;
            }
            else if(input == "q"){
                cout << "Quitting game." << endl;
                return;
            }
            else{
                cout << "That was not r or q. Please try again." << endl;
                cout << "Enter r to start a new game or q to quit." << endl;
            } // else
        } // while
    } // if player is dead
    // restarting the game
    if ( input == "r" ){
        delete player;
        player = NULL;
        cout << "Restarting game."  << endl;
        play(file);
    }
    // handles winning
    if ( floor->getFloornum() == 6) {
        cout << "Care to try again?" << endl;
        cout << "Press r; or q to quit" << endl;
        while(cin >> input) {
            if(input == "q") {
                cout << "Quitting game" << endl;
                return;
            } else if ( input == "r" ) {
                cout << "Restarting game" << endl;
                play(file);
                return;
            } else {
                cout << "Invalid command, try again" << endl;
            } // else
        } // while
    } // if
} // play



// isEnemy
bool Controller::isEnemy(int r, int c){
    // returns true is the entity at r,c is an enemy type.
    if(floor->getCell(r,c) == 'H'){ return true;}
    else if(floor->getCell(r,c) == 'D'){ return true;}
    else if(floor->getCell(r,c) == 'M'){ return true;}
    else if(floor->getCell(r,c) == 'L'){ return true;}
    else if(floor->getCell(r,c) == 'O'){ return true;}
    else if(floor->getCell(r,c) == 'W'){ return true;}
    else if(floor->getCell(r,c) == 'E'){ return true;}
    else{ return false; }
} // isEnemy

