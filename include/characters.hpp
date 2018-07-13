#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP
#include <string>



class Character{

    private:
        int HP;
        int Atk;
        int Def;
        int row; 		    // row position of charactor on the board
        int column; 		// column position of charactor on the board
        std::string race;
        int Gold;
        char prev;
        char symbol;		 // symbol that represents the character on the floor
    public:
        Character(int, int, int, int, int, std::string, int, char, char);
        virtual ~Character();

        int  getHP();
        int  getDef();
        int  getAtk();
        int  getRow();
        int  getCol();
        int  getGold();
        char getPrev();
        char getSymbol();
        std::string getRace();

        void setHP(int);
        void setDef(int);
        void setAtk(int);
        void setRow(int);
        void setCol(int);
        void setGold(int);
        void setPrev(char);

        bool isDead();
};

#endif
