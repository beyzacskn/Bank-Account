#include "CurrentAccount.h"

using namespace std;

CurrentAccount::CurrentAccount(string fName,string lName,int gBalance,int gID):accountType(fName,lName,gID,gBalance,4){}

void CurrentAccount::deposit(int db)
{
    accountType::deposit(db);
}

bool CurrentAccount::withdraw(int wb)
{
    if ((accountType::getBalance()- wb)>0)
    {
        accountType::withdraw(wb);
        return true;
    }
    cout << "hesabinizda yeterli bakiye bulunmamaktadir!!"<<endl;
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
