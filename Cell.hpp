//
// Created by Ryan on 4/11/2023.
//

#ifndef CANTSTOP_CELL_HPP
#define CANTSTOP_CELL_HPP
#include "Player.hpp"



template <class Item> class CList{
private:

    class Cell {
    public:
        Item player;
        Cell* nextCell = nullptr;

        //ostream& print(ostream&);
        ~Cell(){cout << "Deleting player in cell" << endl;
            delete player;
        cout << "Deleted player in cell" << endl;
        }

        //friend ostream& operator <<(ostream& out, Cell& cell);
        inline Cell(Item play):player(play){};

    };

    int cellCount;
    Cell* head;
    Cell* tail;
    Cell* curCell;
public:
    CList();
    ~CList(){
        cout << "Deleting List" << endl;
        if(cellCount !=0) {
            if (head) {
                Cell *c = tail;
                while (c != head) {
                    c->nextCell = head->nextCell;
                    delete head;
                    head = c->nextCell;
                }
                if (c == head) {
                    delete head;
                    head = nullptr;
                }
            }
        }
        curCell = nullptr;
        tail = nullptr;
        cout <<  "Deleted List" << endl;
    } // needs to delete each node
    Item currentPlayer();
    int getCount();
    bool empty();
    ostream& print(ostream&);
    void addCell(Item pl);
    void init();
    Item next();
    void remove();

};
template <class Item> inline ostream& operator <<(ostream& out, CList<Item>& clist){
    return clist.print(out);
}


template <class Item> CList<Item>::CList():cellCount(0),head(NULL){};

template <class Item> Item  CList<Item>::currentPlayer() {
    return curCell->player;
}
template <class Item> int  CList<Item>::getCount() {
    return cellCount;
}

template <class Item> bool  CList<Item>::empty() {
    if(cellCount==0){return true;}
    return false;
}

template <class Item> void  CList<Item>::addCell(Item pl) {
    Cell* it = new Cell(pl);
    if(cellCount ==0) {
        head = it;
        tail = it;
        curCell = it;
        it->nextCell = it;
    }
    else{
        it->nextCell = head;
        tail->nextCell = it;
        tail = it;
    }
    cellCount++;
    /*cout << it->player << endl;
    cout << curCell->player;*/
}

template <class Item> void  CList<Item>::init() {
    if(cellCount != 0) {
        curCell = head;
    }
}

template <class Item> Item CList<Item>::next() {
    curCell = curCell->nextCell;
    return curCell->player;
}
template <class Item> void  CList<Item>::remove() {
    Cell *temp = curCell;
    if (curCell == head) {
        curCell = head->nextCell;
        if(curCell == nullptr){cout << "bruh";}
        delete head;
        head = curCell;
        tail->nextCell = head;
    }
    else {
        while (curCell->nextCell != temp) {
            curCell = curCell->nextCell;
        }
        curCell->nextCell = temp->nextCell;
        delete temp;
    }
    cellCount--;
}
template <class Item> ostream&  CList<Item>::print(ostream & out) {
    for(int c =0; c< cellCount; c++){
        out << c << ":" << *curCell->player;
        next();
    }
    return out;
}




#endif //CANTSTOP_CELL_HPP
