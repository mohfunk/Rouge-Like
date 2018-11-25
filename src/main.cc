#include <iostream>

#include "floor.hpp"
#include "characters.hpp"
#include "players.hpp"
#include "controller.hpp"

int main(int argc, char *argv[]){
    Controller c; // create a controller
    if(argc == 1){
        c.play();
    }
    else{
        std::string s;
        s = argv[1];
        c.play(s); // calls play with the file s, for inputing from a file
    }
}
