#ifndef ITEM_HPP
#define ITEM_HPP


class Item{
    private:
        int row;
        int col;
    public:
        Item();
        ~Item();
        int getRow();
        int getCol();
        void setRow(int);
        void setCol(int);
};

#endif
