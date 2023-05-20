//
// Created by Ryan on 4/11/2023.
//

#include "Cell.hpp"

/*

CList::CList():cellCount(0),head(NULL){};

Player* CList::currentPlayer() {
    return curCell->player;
}
int CList::getCount() {
    return cellCount;
}

bool CList::empty() {
    if(cellCount==0){return true;}
    return false;
}

void CList::addCell(Player* pl) {
    Cell* it = new Cell(pl);
    if(cellCount ==0) {
        cellCount++;
        head = it;
        tail = it;
        curCell = it;
        it->nextCell = it;
    }
    else{
        it->nextCell = tail->nextCell;
        tail->nextCell = it;
        tail = it;
        cellCount++;
    }
    */
/*cout << it->player << endl;
    cout << curCell->player;*//*

}

void CList::init() {
    if(cellCount != 0) {
        curCell = head;
    }
}

Player *CList::next() {
    curCell = curCell->nextCell;
    return curCell->player;
}
void CList::remove() {
    if(curCell == head){
        head = curCell->nextCell;
        delete curCell;
        curCell = head;
        cellCount--;
    }
    else{
        Cell* beforeCell;
        Cell* afterCell;
        for(int dist =0; dist < cellCount-1; dist++){
            curCell = curCell->nextCell;
        }
        beforeCell = curCell;
        curCell = curCell->nextCell;
        afterCell = curCell->nextCell;
        delete curCell;
        curCell = afterCell;
        beforeCell->nextCell = curCell;

        cellCount--;
    }
}
ostream& CList::print(ostream & out) {
    for(int c =0; c< cellCount; c++){
        out << *curCell->player << " ";
        curCell = curCell->nextCell;
    }
    return out;
}
*/
