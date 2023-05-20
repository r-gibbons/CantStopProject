//
// Created by Ryan on 2/5/2023.
//

#include "Column.hpp"
//Marker color order is white,orange,yellow,green,blue

const int column[13] = {0,0,3,5,7,9,11,13,11,9,7,5,3};
Column::Column(int columnNum):columnNum(columnNum),columnState(EColumns::available) {}
//-----------------------------------------------------
bool Column::startTower(Player* player){
    int pColor = int(player->getColor());

    if(columnState != available){
        return false;
    }
    if(markerPos[pColor] != 0 && !columnStarted){
        columnStarted = true;
        markerPos[0] = 1+markerPos[(int)pColor];
        //markerPos[pColor]=0;
        if(markerPos[0] == column[columnNum]){
            columnState = pending;
        }
        return true;
    }
    else{
        move();
        return true;
    }
}

//-----------------------------------------------------
bool Column::move() {
    if(columnState != capture && columnState != pending){
        markerPos[0]++;
        if(markerPos[0] == column[columnNum]){
            columnState = pending;
        }
        return true;
    }
    else{
        return false;
    }
}
//-----------------------------------------------------
ostream& Column::print(ostream &out) {
    out << columnNum << " " << columnNames[int(columnState)] << " ";
        for(int currentSlot =0; currentSlot < column[columnNum];currentSlot++){
            for(int markVal =0; markVal < 5; markVal++){
                if(markerPos[markVal] == 0){
                    out << "-";
                }
                else if(markerPos[markVal] == currentSlot+1) {
                    out << markerNames[markVal];
                }
            }
            out << " ";
        }
        out << endl;
    return out;
}
//-----------------------------------------------------
void Column::stop(Player* player){
    markerPos[int(player->getColor())] = markerPos[int(EColors::white)];
    markerPos[int(EColors::white)] = 0;
    columnStarted = false;
    //cout << markerPos[(int)(player->getColor())] << endl;
    if(columnState == pending){
        columnState = capture;
        player->wonColumn(columnNum);
    }
}
//-----------------------------------------------------
void Column::bust() {
    columnStarted = false;
    markerPos[0] = 0;
}