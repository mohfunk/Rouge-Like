#include "../include/textdisplay.hpp"
#include "../include/characters.hpp"
#include "../include/players.hpp"
#include <string>
#include <iostream>
using namespace std;



// ctor
TextDisplay::TextDisplay(){
    reset();
}



// dtor
TextDisplay::~TextDisplay(){}



// reset
void TextDisplay::reset(){
    // creates an emtpy floor
    for(int i = 0;i < 25;i++){
        for(int j = 0;j < 79;j++){
            if(j == 0 || j == 78){
                floor[i][j] = '|';
            }
            else if(i == 0 || i == 24){
                floor[i][j] = '-';
            }
            else if(i == 2){
                if(j == 2 || j == 29 || j == 38 || j == 62){
                    floor[i][j] = '|';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 62)){
                    floor[i][j] = '-';
                }
                else{
                    floor[i][j] = ' ';
                }

            }
            else if(i == 3){
                if(j == 2 || j == 29 || j == 38 || j == 62){
                    floor[i][j] = '|';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 62)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 4){
                if(j == 2 || j == 62 || j == 70){
                    floor[i][j] = '|';
                }
                else if(j > 62 && j < 70){
                    floor[i][j] = '-';
                }
                else if(j == 29 || j == 38){
                    floor[i][j] = '+';
                }
                else if(j > 29 && j < 38){
                    floor[i][j] = '#';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 62)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 5){
                if(j == 2 || j == 29 || j == 38 || j == 70 || j == 73){
                    floor[i][j] = '|';
                }
                else if(j > 70 && j < 73){
                    floor[i][j] = '-';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 70)){
                    floor[i][j] = '.';
                }
                else if(j == 33){
                    floor[i][j] = '#';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 6){
                if(j == 2 || j == 29 || j == 38 || j == 76 || j == 73){
                    floor[i][j] = '|';
                }
                else if(j > 73 && j < 76){
                    floor[i][j] = '-';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 76)){
                    floor[i][j] = '.';
                }
                else if(j == 33){
                    floor[i][j] = '#';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 7){
                if(j == 2 || j == 29 || j == 38 || j == 60 ||j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 13 || j == 43){
                    floor[i][j] = '+';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 60)){
                    floor[i][j] = '-';
                }
                else if((j > 2 && j < 29) || (j > 38 && j < 76)){
                    floor[i][j] = '.';
                }
                else if(j == 33){
                    floor[i][j] = '#';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 8){
                if(j == 60 ||j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 13 || (j > 30 && j < 44)){
                    floor[i][j] = '#';
                }
                else if((j > 60 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 9){
                if(j == 37 || j == 50 || j == 60 ||j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 43){
                    floor[i][j] = '+';
                }
                else if((j > 37 && j < 50)){
                    floor[i][j] = '-';
                }
                else if(j == 13 || j == 31){
                    floor[i][j] = '#';
                }
                else if((j > 60 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 10){
                if(j == 37 || j == 50 || j == 60 ||j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 13 || j == 31){
                    floor[i][j] = '#';
                }
                else if( (j > 37 && j < 50)|| (j > 60 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 11){
                if(j == 37 || j == 50 ||j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 60){
                    floor[i][j] = '+';
                }
                else if((j > 12 && j < 32) || (j > 53 && j < 60)){
                    floor[i][j] = '#';
                }
                else if( (j > 37 && j < 50)|| (j > 60 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 12){
                if(j == 37 || j == 50 || j == 60 || j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 13 || j == 31 || j == 54){
                    floor[i][j] = '#';
                }
                else if( (j > 37 && j < 50)|| (j > 60 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 13){
                if(j == 37 || j == 50 || j == 60 || j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 43 || j == 69){
                    floor[i][j] = '+';
                }
                else if(j == 13 || j == 31 || j == 54){
                    floor[i][j] = '#';
                }
                else if( (j > 37 && j < 50)|| (j > 60 && j < 76)){
                    floor[i][j] = '-';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 14){
                if(j == 3 || j == 25){
                    floor[i][j] = '|';
                }
                else if(j == 13){
                    floor[i][j] = '+';
                }
                else if(j == 43 || j == 69 || j == 31 || j == 54){
                    floor[i][j] = '#';
                }
                else if(j > 3 && j < 25){
                    floor[i][j] = '-';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 15){
                if(j == 3 || j == 25 || j == 64 || j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 69){
                    floor[i][j] = '+';
                }
                else if(j == 43 || j == 31 || j == 54){
                    floor[i][j] = '#';
                }
                else if(j > 3 && j < 25){
                    floor[i][j] = '.';
                }
                else if(j > 64 && j < 76){
                    floor[i][j] = '-';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 16){
                if(j == 3 || j == 25 || j == 64 || j == 76){
                    floor[i][j] = '|';
                }
                else if( j >= 31 && j <= 54){
                    floor[i][j] = '#';
                }
                else if((j > 3 && j < 25) || (j > 64 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 17){
                if(j == 3 || j == 25 || j == 64 || j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 43 || j == 31){
                    floor[i][j] = '#';
                }
                else if((j > 3 && j < 25) || (j > 64 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 18){
                if(j == 3 || j == 25 || j== 36 || j == 64 || j == 76){
                    floor[i][j] = '|';
                }
                else if( j == 43 ){
                    floor[i][j] = '+';
                }
                else if( j == 31 ){
                    floor[i][j] = '#';
                }
                else if(j > 36 && j < 64){
                    floor[i][j] = '-';
                }
                else if((j > 3 && j < 25) || (j > 64 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 19){
                if(j == 3 || j == 25 || j== 36 || j == 76){
                    floor[i][j] = '|';
                }
                else if( j == 31 ){
                    floor[i][j] = '#';
                }
                else if((j > 3 && j < 25) || (j > 36 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 20){
                if(j == 3 || j == 76){
                    floor[i][j] = '|';
                }
                else if(j == 25 || j== 36){
                    floor[i][j] = '+';
                }
                else if( j > 25 && j < 36){
                    floor[i][j] = '#';
                }
                else if((j > 3 && j < 25) || (j > 36 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 21){
                if(j == 3 || j == 76 || j == 25 || j== 36){
                    floor[i][j] = '|';
                }
                else if((j > 3 && j < 25) || (j > 36 && j < 76)){
                    floor[i][j] = '.';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else if(i == 22){
                if(j == 3 || j == 76 || j == 25 || j== 36){
                    floor[i][j] = '|';
                }
                else if((j > 3 && j < 25) || (j > 36 && j < 76)){
                    floor[i][j] = '-';
                }
                else{
                    floor[i][j] = ' ';
                }
            }
            else{
                floor[i][j] = ' ';
            } // else
        } // for
    } // for
} // reset



// print
void TextDisplay::print(){
    for(int i = 0; i < 25;i++){
        for(int j = 0; j < 79;j++){
            cout << floor[i][j];
        }
        cout << endl;
    }
}
