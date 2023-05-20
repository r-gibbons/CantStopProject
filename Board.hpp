//
// Created by Haugh on 2/22/2023.
//

#ifndef CANTSTOP_BOARD_HPP
#define CANTSTOP_BOARD_HPP
#include "Column.hpp"
#include "tools.hpp"

class Board {
private:
    int towerCount;
    Column* backBone [13];
    Player* currentPlayer;
    int bLen = 13;
    int usedColumns[3];
public:
    Board();
    ~Board(){
        cout << "deleting board" << endl;
        for(int b =0; b < bLen; b++){delete [] backBone[b];
        }
        cout << "Deleted board" << endl;
    }
    void StartTurn(Player* player);
    ostream& print(ostream&);
    bool Move(int column);
    bool CheckCol(int col);
    void Stop();
    void Bust();
};
inline ostream& operator <<(ostream& out, Board& board){
    return board.print(out);
}

#endif //CANTSTOP_BOARD_HPP
