#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>

#include "accountType.h"

using namespace std;

accountType::accountType(string gfName,string glName,int gaccountID,int gBalance,int gClassType)
{
    firstName = gfName;
    lastName = glName;
    ID = gaccountID;
    balance = gBalance;
    firstBalance = balance;
    classType = gClassType;
}

void accountType::setFirstName(string fName)
{
   firstName = fName;
}

void accountType::setLastName(string lName)
{
    lastName=lName;
}

string accountType::getFirstName()
{
    return firstName;
}

string accountType::getLastName()
{
    return lastName;
}

int accountType::getBalance()
{
    return balance;
}

int accountType::getFirstBalance()
{
    return firstBalance;
}

int accountType::getClassType()
{
    return classType;
}

void accountType::sonBesIslem()
{
    int i=0;
    while(hesapOzet[i]!="")
    {
        i++;
    }
    for(int j=i;j>=0;j--)
    {
        cout << hesapOzet[j] << endl;
    }
}

int accountType::getID()
{
    return ID;
}
void accountType::withdraw(int wb)
{
    balance -= wb;
    std::string out_string;
    std::stringstream ss;
    ss << wb;
    out_string = ss.str();
    string islem = out_string + " TL cekildi.";
    if(hesapOzet[0]=="")
        hesapOzet[0] = islem;
    else
    {
        int i=0;
        while(hesapOzet[i]!="")
        {
            i++;
        }
        hesapOzet[i] = islem;
    }
    cout << islem << endl;
}

void accountType::deposit(int db)
{
    balance += db;
    std::string out_string;
    std::stringstream ss;
    ss << db;
    out_string = ss.str();
    string islem = out_string + " TL yatirildi.";
    if(hesapOzet[0]=="")
        hesapOzet[0] = islem;
    else
    {
        int i=0;
        while(hesapOzet[i]!="")
        {
            i++;
        }
        hesapOzet[i] = islem;
    }
    cout << islem << endl;
}

void accountType::benefit(tm tarih,int interester)
{
    double gunSayisi;
    int faizTutar;
    time_t x = mktime(&acilisTarihi);
    time_t y = mktime(&tarih);
    if ( x != (time_t)(-1) && y != (time_t)(-1) )
    {
        gunSayisi = difftime(y, x) / (60 * 60 * 24);
    }
    faizTutar = balance* interester*(gunSayisi/365);
    balance += faizTutar;
}
