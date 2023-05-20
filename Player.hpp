//
// Created by Ryan on 1/27/2023.
//

#ifndef CANTSTOP_PLAYER_HPP
#define CANTSTOP_PLAYER_HPP
#include "tools.hpp"
#include "Enums.hpp"

class Player {
private:
    string playerName;
    EColors playerColor;
    int score;
    int* scoreboard;

public:
    Player(string name,char color);
    ~Player(){
        cout << "deleting scoreboard of " << playerName << endl;
        delete [] scoreboard;
        cout << "Deleted Scoreboard" <<endl;
    }
    ostream& print(ostream&);
    EColors getColor();
    int getScore();
    string getName();
    bool wonColumn(int colNum);
    EColors setColor(char color);

};
inline ostream& operator <<(ostream& out, Player& player){
    return player.print(out);
}


#endif //CANTSTOP_PLAYER_HPP
