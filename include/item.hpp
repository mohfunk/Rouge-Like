#ifndef ITEM_HPP
#define ITEM_HPP

class Item{
	int row;
	int col;
      public:
	Item();
	~Item();
	// returns the row
	int getRow();
	// return the column
	int getCol();
	// sets the row
	void setRow(int);
	// sets the column
        void setCol(int);
};

#endif
