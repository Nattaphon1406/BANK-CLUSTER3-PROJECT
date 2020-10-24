#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <sstream>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
#include <ctime>
using namespace std;
class BankAccount : public Information{
    private:
        class statementBill{
            public:
                string Name,AccountNumber,Money,Date,Time;
                statementBill *linkBill;
                statementBill(string name,string accountNumber,string money,string date,string time);
                //Call Funtion Info From class Person
        };
        statementBill *headBill, *tailBill, *tempBill;
        BankAccount *Obj_BankAccount;
        Info_BankAccount *temp;
        string accountNumber, NameAccount;
        double moneyAccount;
        int countStatment;
    public:
        BankAccount();
        void AddStatementBill(string name,string accountNumber,string money,string date,string time);
        bool CheckTransfer_account(string accountNumber);
        double getMoneyAccount(string username);
        string setDateandTime();
        void payBill(string group, string username, double amount);
        void WriteStatement();
    
};
#endif