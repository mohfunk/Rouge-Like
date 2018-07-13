#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include<string>

class Floor;

class TextDisplay{
friend class Floor;
	char floor[25][79];
      public:	
	TextDisplay(); // constructor
	~TextDisplay(); // dtor
	// prints the floor
	void print();
	// resets the floor
	void reset();
};

#endif
