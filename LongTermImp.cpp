#include <iostream>
#include <ctime>

#include "LongTermAccount.h"

using namespace std;

LongTermAccount::LongTermAccount(string fName,string lName,int gbalance, int gID):accountType(fName,lName,gID,gbalance,2)
{
    interester=24;
}

void LongTermAccount::deposit(int db)
{
    accountType::deposit(db);
}

bool LongTermAccount::withdraw(int wb)
{
    if((accountType::getBalance()-wb>1500))
    {

        accountType::withdraw(wb);
        return true;
    }
    cout << "hesabinizda yeterli bakiye bulunmamaktadir!!"<<endl;
    return false;
}

int LongTermAccount::benefit(tm now)
{
    accountType::benefit(now,interester);
}
