#include <iostream>
#include <ctime>

#include "SpecialAccount.h"

using namespace std;

SpecialAccount::SpecialAccount(string fName,string lName,int gBalance,int ID):accountType(fName,lName,ID,gBalance,3)
{
    interester = 12;
}

void SpecialAccount::deposit(int db)
{
    accountType::deposit(db);
}

bool SpecialAccount::withdraw(int wb)
{
    if((accountType::getBalance()-wb)>accountType::getFirstBalance())
    {

        accountType::withdraw(wb);
        return true;
    }
    cout << "hesabinizda yeterli bakiye bulunmamaktadir!!"<<endl;
    return false;
}

void SpecialAccount::benefit(tm now)
{
    accountType::benefit(now,interester);
}
