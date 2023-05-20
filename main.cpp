//
// Created by Ryan on 1/22/2023.
//
#include "tools.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Column.hpp"
#include "Game.hpp"
#include "Board.hpp"
#include "Cell.hpp"
void unitDice();
void unitPlayer();
void unitColumn();
void unitGame();
void unitBoard();
void unitCell();

int main() {
    banner();
    unitGame();
    //unitCell();
    bye();
    cout << "bye" << endl;
    return 0;
}
void unitCell(){
    /*Player* p1 = new Player("Me",'O');
    Player* p2 = new Player("You",'Y');
    Player p3("Us",'G');
    CList list;
    Cell* c = new Cell(p1);
    Cell* d = new Cell(p2);
    list.addCell(c);
    list.addCell(d);

    cout << list << endl;
    list.next();
    list.remove();
    cout << list << endl;*/

}
void unitBoard(){
    Board B;
    cout << B;
}
//-----------------------------------------------------
void unitGame(){
    /*cout << "Expected output" << endl;
    cout << "Enter Color(0,Y,G,B)" << endl;
    cout << "1: Roll - 2:Stop - 3:Resign" << endl;
    cout << "User entering 1 will cause game to continue, while entering 2 will stop the turn" << endl;
    cout << "If 1 is entered" << endl;
    cout << "A: (random number 1-6)" << endl;
    cout << "B: (random number 1-6)" << endl;
    cout << "C: (random number 1-6)" << endl;
    cout << "D: (random number 1-6)" << endl;
    cout << "User enters number and board gets displayed with towers played" << endl;
    cout <<  "This loop continues until the player presses stop" << endl;
    cout << "Once stopped board will be displayed with markers displayed instead of towers" << '\n' << endl;*/

    Game TestGame;
    TestGame.Run();

    //TestGame.Run();

}
//-----------------------------------------------------
void unitColumn(){
    Player Tom("Tom",'O');
    Player Jerry("Jerry",'B');

    Column C2(2);
    C2.startTower(&Tom);
    C2.move();
   // C2.move();
    C2.stop(&Tom);
    cout << C2;

    Column C7(7);
    C7.startTower(&Jerry);
    C7.move();
    cout << C7;
}
//-----------------------------------------------------
void unitPlayer(){
   // cout << "Will Display 3 Correctly Made Players Including Their Name, Color, Score and The Last Player Has" << '\n'
     //        <<"An Invalid Color And Calls Fatal" << '\n' << endl;
    //Player P("Jerry",'W');
    //cout << P;
    Player L("Stitch",'O');
    //cout << L;
    Player A("Tom",'B');
    //cout << A;
   // Player Y("Joe",'q');
   // cout << Y;

    cout << L.wonColumn(2);
    cout << L.wonColumn(3);
    cout << L.wonColumn(4);


}
//-----------------------------------------------------
void unitDice(){
    cout << "Expected Output: dice equal to test number " << endl;
    cout << "Dice Value: between 1-6" << endl;
    for(int i =1; i < 26; i++){
        cout << "Test:" << i << endl;
        Dice D(i);
        D.roll();
        cout << D << endl;
    }
}
