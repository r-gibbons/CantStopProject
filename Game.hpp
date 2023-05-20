//
// Created by Ryan on 2/15/2023.
//

#ifndef CANTSTOP_GAME_HPP
#define CANTSTOP_GAME_HPP
#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"
#include "Board.hpp"
#include "Cell.hpp"
#include "BadPlayer.hpp"
#include "BadChoice.hpp"
class Game {
private:
    Dice* diceSet;
    //CantStopDice CSDice;
    //FakeDice fakeDice;
    CList<Player*> playerList;
    Player* player;
    Board board;
    Status gameStatus;

    char inputOptions[4] = {'A','B','C','D'};
    string unusedColors = "OYGB";
    const int* curDice;
    int toMove[2];
    char input[2] = {'0', '0'};
    bool isPlaying;
    bool isOver;
public:
    Game();
    ~Game(){ cout << "Deleting game diceSet" << endl;
        delete diceSet;
        cout << "Deleted game diceSet" << endl;
    };
    void testOneTurn();
    void Run();
    void oneTurn(Player* pp);
    void validateChoice(char input);
    Player* getNewPlayer();
    void validatePlayer(string vPlayer, char c);
    bool CheckInput(char input);
    int* combineValues(char diceOne, char diceTwo);
    void matchPlayer(int pos);
    //void combineValues(char input[]);
    bool performMove();
};


#endif //CANTSTOP_GAME_HPP
