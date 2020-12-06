#include <iostream>

#include "ShortTermAccount.h"

using namespace std;

ShortTermAccount::ShortTermAccount(string fName,string lName,int gBalance,int gID):accountType(fName,lName,gID,gBalance,1)
{
    interester = 17;
}


void ShortTermAccount::deposit(int db)
{
    accountType::deposit(db);
}

bool ShortTermAccount::withdraw(int wb)
{
    if((accountType::getBalance()-wb)>=1000)
    {
        accountType::withdraw(wb);
        return true;
    }
    cout << "hesabinizda yeterli bakiye bulunmamaktadir!!"<<endl;
    return false;
}

void ShortTermAccount::benefit(tm now)
{
    accountType::benefit(now,interester);
}
