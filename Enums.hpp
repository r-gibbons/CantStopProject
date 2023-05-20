//
// Created by Ryan on 1/27/2023.
//

#ifndef CANTSTOP_ENUMS_HPP
#define CANTSTOP_ENUMS_HPP

#include "tools.hpp"

enum  EColors {white,orange,yellow,green,blue};
enum EColumns{available,pending,capture};
enum Status{Begin,Done,Quit};

extern const string statusNames[3];
extern const string colorNames[5];
extern const string columnNames[3];
extern const string markerNames[5];
enum ETiles{W,O,Y,G,B};


#endif //CANTSTOP_ENUMS_HPP
