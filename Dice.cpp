//
// Created by Ryan on 1/22/2023.
//

#include "Dice.hpp"
//-------------------Base Die Class------------------------
Dice::Dice(int n):nDice(n),diceSet(new int[nDice]){
    srand(time(NULL));
}
//fills variable sized array with a number 1-6
/*const int* Dice::roll(){
    for(int rollCount =0; rollCount < nDice; rollCount++){
        diceSize[rollCount]= rand() %numSides+1;
    }
    return diceSize;
}*/
const int* Dice::roll(){
    for(int rollCount =0; rollCount < nDice; rollCount++){
        diceSet[rollCount]= rand() %numSides+1;
    }
    return diceSet;
}
//prints all values rolled in format
ostream& Dice::print(ostream & out) {
    for(int i=0; i<nDice;i++){
        out << diceSet[i] << " ";
    }
    return out;
}

//----------------- Cant Stop Dice -------------------------
CantStopDice::CantStopDice():Dice(4){}
const int* CantStopDice::roll() {
    bool success = false;
    Dice::roll();
    while(!success) {
        displayRoll();
        readInput();

        try {
            validateDice();
            success = true;
        }
        catch (BadChoice &bc) {
            bc.print();
            /*displayRoll();
            readInput();
            validateDice();*/
        }
    }
    dicePairs[0] = diceSet[dieChoice[0]] + diceSet[dieChoice[1]];
    dicePairs[1] = totalAmt - dicePairs[0];
    cout << diceSet[0] << "  " << diceSet[1] << "  " << diceSet[2] << "   " << diceSet[3] << endl;
    cout << dicePairs[0] << "   " << dicePairs[1] << endl;
    //cout << "First:"<<dicePairs[0] << "       Second:" << dicePairs[1] << endl;
    return dicePairs;
}
void CantStopDice::readInput(){
    dieChoice[0] = 0;
    dieChoice[1] = 0;
    cout << "Enter Pair With Greatest Priority:" <<endl;
    cin >> input[0] >> input[1];
    input[0] = toupper(input[0]);
    input[1] = toupper(input[1]);
}
void CantStopDice::displayRoll() {
    totalAmt = 0;
    for (int size = 0; size < 4; size++) {
        cout << labels[size] << ":" << diceSet[size] << " ";
        totalAmt += diceSet[size];
    }
}
void CantStopDice::validateDice() {
    dieChoice[0] = labels.find_first_of(input[0]);
    dieChoice[1] = labels.find_first_of(input[1]);

    if(input[0] == input[1]) {
        throw(DuplicateSlot(dieChoice[0]));
    }
    if(dieChoice[0] == string::npos){
        throw(BadSlot(dieChoice[0]));
    }
    if(dieChoice[1] == string::npos){
        throw(BadSlot(dieChoice[1]));
    }
}
//----------------FakeDice--------------------------------------------
FakeDice::FakeDice() {
    fakeDiceRolls.open(TestDice);               // 0 = play    -1 = stop     -3 = resign game
    if(!fakeDiceRolls){
        fatal("Test file was not opened successfully");
    }
}

const int *FakeDice::roll() {
    bool success = false;
    if(!fakeDiceRolls.eof()){fakeDiceRolls >> diceNums[0] >> diceNums[1] >> diceNums[2] >> diceNums[3];}
    else{ fatal("End of file: Did not complete game");}
    while (!success) {
        displayRoll();
        CantStopDice::readInput();

        try {
            validateDice();
            success = true;
        }
        catch (BadChoice &bc) {
            bc.print();
            /*displayRoll();
            readInput();
            validateDice();*/
        }
    }
    dicePairs[0] = diceNums[dieChoice[0]] + diceNums[dieChoice[1]];
    dicePairs[1] = totalAmt - dicePairs[0];

    return dicePairs;
}

void FakeDice::validateDice() {
    dieChoice[0] = labels.find_first_of(input[0]);
    dieChoice[1] = labels.find_first_of(input[1]);

    if(input[0] == input[1]) {
        throw(DuplicateSlot(dieChoice[0]));
    }
    if(dieChoice[0] == string::npos){
        throw(BadSlot(dieChoice[0]));
    }
    if(dieChoice[1] == string::npos){
        throw(BadSlot(dieChoice[1]));
    }
}

void FakeDice::displayRoll() {
    totalAmt = 0;
    for (int size = 0; size < 4; size++) {
        cout << labels[size] << ":" << diceNums[size] << "    ";
        totalAmt += diceNums[size];
    }
}