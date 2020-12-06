#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <iostream>
#include <ctime>

#include "accountType.h"
using namespace std;

class Bank
{
private:
    accountType *hesapListesi[100];
    int countAccounts=0;
    time_t tarih = time(0);
    tm *t= gmtime(&tarih);
public:
    void sonBesIslem();
    void addAccount(accountType account);
    void getAccount();
    void setDate(int y, int m,int d);
    tm getDate();
    bool deposit(int id,int cash);
    bool withDraw(int id,int cash);
    bool IDSorgula(int id);
    bool isEmpty();
    void faizHesabi();
    int sortition(int len);
};

#endif // BANK_H_INCLUDED
