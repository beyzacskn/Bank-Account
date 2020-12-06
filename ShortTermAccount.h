#ifndef SHORTTERMACCOUNT_H_INCLUDED
#define SHORTTERMACCOUNT_H_INCLUDED

#include <iostream>
#include <string>
#include "accountType.h"

class ShortTermAccount:public accountType
{
private:
    int interester;
public:
    ShortTermAccount(string fName="", string lName= "",int gBalance=0,int gID=0);
    void deposit(int db);
    bool withdraw(int wb);
    void benefit(tm now);
};

#endif // SHORTTERMACCOUNT_H_INCLUDED
