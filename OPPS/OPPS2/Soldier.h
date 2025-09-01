#ifndef SOLDIER_H
#define SOLDIER_H

#include<iostream>
#include "person.h"
using namespace std;

class Soldier:public person
{
public:
    Soldier();
    void FireWeapon();
};

#endif