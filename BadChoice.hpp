//
// Created by Ryan on 5/5/2023.
//

#ifndef CANTSTOP_BADCHOICE_HPP
#define CANTSTOP_BADCHOICE_HPP
#include "tools.hpp"

class BadChoice {
public:
    char choice;
    BadChoice(char ch):choice(ch){};
    virtual ~BadChoice()=default;
    virtual void print(){
        cout << "Chosen move is invalid\n"
        << "1->Roll | 2->Stop | 3->Quit\n"
        << "You Entered " << choice << endl;
    }
};
class DuplicateSlot: public BadChoice{
public:
    DuplicateSlot(char ch): BadChoice(ch){};
    virtual ~DuplicateSlot(){};
    virtual void print(){
        cout << "Invalid Input: Same slot entered twice\n"
        << "You entered " << choice << "\n"
        << "Please input a valid pair" << endl;
    }

};
class BadSlot: public BadChoice{
public:
    BadSlot(char ch): BadChoice(ch){};
    virtual ~BadSlot(){};
    virtual void print(){
        cout << "Invalid Input: Slot chosen is not an option\n"
        << "You entered " << choice << "\n"
        << "Please input a valid pair" <<  endl;
    }
};

#endif //CANTSTOP_BADCHOICE_HPP
