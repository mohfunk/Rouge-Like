#include "../include/floor.hpp"
#include "../include/characters.hpp"
#include "../include/players.hpp"
#include "../include/controller.hpp"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    Controller c; // create a controller
    if(argc == 1){
        c.play();
    }
    else{
        string s;
        s = argv[1];
        c.play(s); // calls play with the file s, for inputing from a file
    }
}
