//
// Created by Haugh on 2/22/2023.
//

#include "Board.hpp"
//----------------------------------------------
Board::Board() {
    for(int k=0; k < bLen; k++){
            backBone[k] = new Column(k);
    }
}
//----------------------------------------------
void Board::StartTurn(Player *curPlayer) {
    currentPlayer = curPlayer;
    towerCount = 0;
}
//----------------------------------------------
bool Board::Move(int col){
    if(CheckCol(col)){
        backBone[col]->startTower(currentPlayer);
        return true;
    }
    else if(towerCount == 3 || backBone[col]->getState() != available){
        return false;
    }

    //for(int pos =0; pos < 3; pos++) {
        usedColumns[towerCount++] = col;
        backBone[col]->startTower(currentPlayer);
    //}
    return true;
}
//-------------------------------------------------
bool Board::CheckCol(int col) {
    for(int pos=0; pos < towerCount; pos++){
        if(usedColumns[pos] == col) {
            return true;
        }
    }
    return false;
}
//----------------------------------------------
void Board::Stop(){

    for(int col=0; col < towerCount; col++){
        int column = usedColumns[col];
        backBone[column]->stop(currentPlayer);
        usedColumns[col] = 0;
    }
}
//----------------------------------------------
ostream& Board::print(ostream &out) {
    for(int curCol =2; curCol < bLen; curCol++){
        out << *backBone[curCol];
    }
    out << endl;
    return out;
}
void Board::Bust(){
    for(int col =0; col < towerCount; col++){
        backBone[usedColumns[col]]->bust();
    }
}
