#include <iostream>
#include <string>

#include "CurrentAccount.h"

using namespace std;

CurrentAccount::CurrentAccount(string fName,string lName,int gBalance,int gID,int gClassType):accountType(fName,lName,gID,gClassType)
{
    balance = gBalance;
}

int CurrentAccount::getBalance()
{
    return balance;
}

void CurrentAccount::deposit(int db)
{
    balance = balance + db;
}

bool CurrentAccount::withdraw(int wb)
{
    if ((balance- wb)>0)
    {
        balance = balance - wb;
        return true;
    }
    return false;
}

int CurrentAccount::getID()
{
    int r=accountType::getID();
    return r;
}

int CurrentAccount::benefit()
{
    return 0;
}
