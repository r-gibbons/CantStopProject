//
// Created by Ryan on 1/27/2023.
//

#include "Player.hpp"

//constructor
//-----------------------------------------------------
Player::Player(string name, char color):scoreboard(new int[3]),playerName(name),playerColor(setColor(color)),score(0){}

//ties the user entered value for color with enum
//-----------------------------------------------------
EColors Player::setColor(char color) {
    switch(color){
        case 'O':
            return EColors::orange;
        case 'Y':
            return EColors::yellow;
        case 'G':
            return EColors::green;
        case 'B':
            return EColors::blue;
        default:
            fatal("Not A Valid Color");
    }
    return playerColor;
}
string Player::getName() {
    return playerName;
}
//-----------------------------------------------------
EColors Player::getColor() {
    return playerColor;
}
//returns score of the game
//-----------------------------------------------------
int Player::getScore(){
    return score;
}
//adds column number when a player wins the column and returns a win condition
//-----------------------------------------------------
bool Player::wonColumn(int colNum) {
    score++;
    scoreboard[score]=colNum;
    return (score == 3);
}
//prints data members of player
//-----------------------------------------------------
ostream& Player::print(ostream & out) {

    out << playerName << " " << colorNames[(int)playerColor] << " Score: " << score << endl;
    return out;
}