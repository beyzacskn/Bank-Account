#include <iostream>
#include <time.h>
#include <cstdlib>

#include "Bank.h"
#include "accountType.h"
#include "SpecialAccount.h"
#include "LongTermAccount.h"
#include "ShortTermAccount.h"
#include "CurrentAccount.h"

using namespace std;

using namespace std;

void Bank::getAccount()
{
    for(int i=0;i<countAccounts;i++)
    {
        cout << "Hesap ID: " << hesapListesi[i]->getID() << " , Bakiye: " << hesapListesi[i]->getBalance() << endl;
    }
}

void Bank::sonBesIslem()
{
    if(isEmpty())
    {
        cout << "Henuz hesap eklenmemistir!!"<< endl;
    }
    else
    {
        for (int i = 0 ; i < countAccounts;i++)
        {
            cout << "ID : "<< hesapListesi[i]->getID()
            << "\tSon bes islem : ";
            hesapListesi[i]->sonBesIslem();
            cout<<endl;
        }
    }

}

void Bank::setDate(int y , int m, int d)
{
*t = {0,0,0,d,m,y};
}

void Bank::addAccount(accountType acc)
{
    hesapListesi[countAccounts] = &acc;
    countAccounts++;
}

bool Bank::deposit(int id,int cash)
{
    if(isEmpty())
    {
        cout << "Henuz hesap eklenmemistir!!" << endl;
    }
    else
    {
        for(int i=0;i<countAccounts;i++)
        {
            if(hesapListesi[i]->getID()==id)
            {
                hesapListesi[i]->deposit(cash);
                return true;
            }
        }
        cout << "Girilen ID'ye ait hesap bulunamadi!" << endl;
    }

    return false;
}

bool Bank::withDraw(int id,int cash)
{
    if(isEmpty())
    {
        cout << "Henuz hesap eklenmemistir!!" << endl;
    }
    else
    {
        for(int i=0;i<countAccounts;i++)
        {
            if(hesapListesi[i]->getID()==id)
            {
                if(hesapListesi[i]->getClassType()==1)
                {
                    ShortTermAccount *ptr;
                    ptr = (ShortTermAccount*)hesapListesi[i];
                    ptr->ShortTermAccount::withdraw(cash);
                    return true;
                }
                else if(hesapListesi[i]->getClassType()==2)
                {
                    LongTermAccount *ptr;
                    ptr = (LongTermAccount*)hesapListesi[i];
                    ptr->LongTermAccount::withdraw(cash);
                    return true;
                }
                else if(hesapListesi[i]->getClassType()==3)
                {
                    SpecialAccount *ptr;
                    ptr = (SpecialAccount*)hesapListesi[i];
                    ptr->SpecialAccount::withdraw(cash);
                    return true;
                }
            }
        }
        cout << "Girilen ID'ye ait hesap bulunamadi!" << endl;
    }
    return false;
}

tm Bank::getDate()
{
    return *t;
}

bool Bank::IDSorgula(int id)
{
    bool dogruMu=false;
    if(isEmpty()){}
    else
    {
        int i = 0;
        while(!dogruMu && i<countAccounts)
        {
            if (hesapListesi[i]->getID()==id)
            {
                dogruMu = true;
            }
            i++;
        }
    }

    return dogruMu;
}

bool Bank::isEmpty()
{
    return countAccounts==0;
}
