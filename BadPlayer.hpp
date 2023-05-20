//
// Created by Haugh on 4/28/2023.
//

#ifndef CANTSTOP_BADPLAYER_HPP
#define CANTSTOP_BADPLAYER_HPP
#include "tools.hpp"


class BadPlayer {
public:
    string pName;
    char pColor;

    BadPlayer(string n, char c):pName(n),pColor(c){};
    virtual ~BadPlayer()= default;
    virtual void print(){
        cout << "Player name and color are invalid" << endl;
        pr();
    }
    void pr(){
        cout << "You Entered name of " << pName << " and color of " << pColor <<"\n"
                <<"Please reenter :";
    }

};
class BadName: public BadPlayer{
public:
    BadName(string n, char c): BadPlayer(n,c){};
    virtual ~BadName(){}
    virtual void print() {
        cout << "Player name entered is invalid" << endl;
        pr();
    }
};
class BadColor : public BadPlayer{
public:
    BadColor(string n, char c): BadPlayer(n,c){};
    virtual ~BadColor(){};
    virtual void print(){
        cout << "The color entered is not a valid color" << endl;
        pr();
    }
};


#endif //CANTSTOP_BADPLAYER_HPP
