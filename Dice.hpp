//
// Created by Ryan on 1/22/2023.
//

#ifndef CANTSTOP_DICE_HPP
#define CANTSTOP_DICE_HPP
#define TestDice "fakeDice.txt"
#include "tools.hpp"
#include "BadChoice.hpp"
class Dice {
protected:
    int nDice;
    int* diceSet;
    const int numSides =6;
public:
    Dice(int = 6);
    virtual ~Dice(){ cout << "deleting dice diceset" << endl;
        delete [] diceSet;
        cout << "Deleted dice diceSet" << endl;
    }
    virtual const int* roll();
    //void roll();
    ostream& print(ostream&);
};

class CantStopDice : public Dice{
protected:
    int dicePairs[2];
    int dieChoice [2];
    string labels = "ABCD";
    int totalAmt;
    char input [2];
public:
    CantStopDice();
    ~CantStopDice(){
        cout << "Deleting CantStopDice" << endl;
        //delete [] diceSet;
        cout << "Deleted CantStopDice" << endl;
    }
    const int* roll();
    void displayRoll();
    void readInput();
    void validateDice();
};
inline ostream& operator <<(ostream& out, Dice& dice){
    return dice.print(out);
}

class FakeDice : public CantStopDice{
private:
    ifstream fakeDiceRolls;
    int dicePairs[2];
    int diceNums [4];
    string labels = "ABCD";
    int totalAmt;
public:
    FakeDice();
    ~FakeDice(){
        cout << "closing file" << endl;
        fakeDiceRolls.close();
        cout << "Closed file" << endl;
    }
    char move();
    void displayRoll();
    void validateDice();
    const int* roll();
};




#endif //CANTSTOP_DICE_HPP
