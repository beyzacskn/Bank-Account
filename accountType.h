#ifndef ACCOUNTTYPE_H_INCLUDED
#define ACCOUNTTYPE_H_INCLUDED

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class accountType
{
private:
    string firstName;
    string lastName;
    string hesapOzet[100];
    int ID;
    int balance=0;
    int firstBalance;
    int classType;
    tm acilisTarihi = {0,0,0,1,0,117};
public:
    accountType(string gfName="",string glName="",int gaccountID=0,int gBalanc=0,int gClassType=0);
    void setFirstName(string fName);
    void setLastName(string lName);
    string getFirstName();
    string getLastName();
    int getBalance();
    int getFirstBalance();
    int getClassType();
    int getID();
    void deposit(int db);
    void withdraw(int wb);
    void sonBesIslem();
    void benefit(tm tarih,int interester);
};

#endif // ACCOUNTTYPE_H_INCLUDED
