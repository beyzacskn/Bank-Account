#ifndef CURRENTACCOUNT_H_INCLUDED
#define CURRENTACCOUNT_H_INCLUDED

#include <string>

#include "accountType.h"

using namespace std;

class CurrentAccount : public accountType {
private:
public:
    CurrentAccount(string fName="",string lName="",int gbalance=0, int gID=0);
    int getID();
    void deposit(int db);
    bool withdraw(int wb);
    int benefit();
};

#endif // CURRENTACCOUNT_H_INCLUDED
