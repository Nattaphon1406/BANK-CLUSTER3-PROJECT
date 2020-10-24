#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <sstream>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
using namespace std;
class BankAccount : public Information{
    private:
        BankAccount *Obj_BankAccount;
        Info_BankAccount *temp;
    public:
        bool CheckTransfer_account(string accountNumber);
        string getMoneyAccount(string username);
        void payBill(string group, string username, double moneyAccount, double amount);
        void chengceDataFile();
    
};
#endif