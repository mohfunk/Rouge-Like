#ifndef TEXTDISPLAY_HPP
#define TEXTDISPLAY_HPP
#include<string>

class Floor;

class TextDisplay{
    friend class Floor;
    char floor[25][79];
    public:	
    TextDisplay(); 
    ~TextDisplay();
    void print();
    void reset();
};

#endif
