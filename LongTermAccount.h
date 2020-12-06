#ifndef LONGTERMACCOUNT_H_INCLUDED
#define LONGTERMACCOUNT_H_INCLUDED
#include <string>
#include <ctime>
#include "accountType.h"

using namespace std;

class LongTermAccount:public accountType
{
private:
    int interester;
public:
    LongTermAccount(string fName="", string lName= "",int gBalance=0,int gID=0);
    int getInterest();
    void deposit(int db);
    bool withdraw(int wb);
    int benefit(tm now);
};

#endif // LONGTERMACCOUNT_H_INCLUDED
