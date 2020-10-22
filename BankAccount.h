#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
using namespace std;
class BankAccount : public Information{
    private:
        BankAccount *Obj_BanKAcount;
    public:
        void Check();

    
};
#endif