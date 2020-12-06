#ifndef SPECIALACCOUNT_H_INCLUDED
#define SPECIALACCOUNT_H_INCLUDED
#include <string>
#include "accountType.h"

using namespace std;

class SpecialAccount:public accountType
{
private:
    int interester;
public:
    SpecialAccount(string fName="", string lName= "",int gBalance=0,int gID=0);
    void deposit(int db);
    bool withdraw(int wb);
    void benefit(tm now);
};

#endif // SPECIALACCOUNT_H_INCLUDED
