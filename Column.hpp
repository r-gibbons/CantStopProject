//
// Created by Ryan on 2/5/2023.
//

#ifndef CANTSTOP_COLUMN_HPP
#define CANTSTOP_COLUMN_HPP
#include "tools.hpp"
#include "Enums.hpp"
#include "Player.hpp"
extern const int column [13];
class Column {
private:

    EColumns columnState = available;
    EColors Markers;
    bool columnStarted=false;
                            // T,O,Y,G,B
    int markerPos [5] = {0,0,0,0,0};
    int columnNum;
    int colLen = 13;

public:
    Column(int columnNum);
    /*~Column(){
        cout <<  "Deleting column" << endl;
    };*/
    EColumns getState(){return columnState;};
    ostream& print(ostream&);
    bool startTower(Player* player);
    void stop(Player* player);

    bool move();
    void bust();
};
inline ostream& operator <<(ostream& out, Column& column){
    return column.print(out);
}


#endif //CANTSTOP_COLUMN_HPP
