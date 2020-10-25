#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <sstream>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
#include <time.h>
using namespace std;
class BankAccount : public Information{
    private:
        class statementBill{
            public:
                string Name,AccountNumber,Money,Date,Time;
                statementBill *linkBill;
                statementBill(string name,string accountNumber,string money,string date,string time);
        };
        class statementBillBankclerk{
            public:
                string Type,Money,Date,Time;
                statementBillBankclerk *linkBillBankclerk;
                statementBillBankclerk(string type,string money,string date,string time);
        };
        statementBill *headBill, *tailBill, *tempBill;
        statementBillBankclerk *headBillBankclerk, *tailBillBankclerk, *tempBillBankclerk;
        BankAccount *Obj_BankAccount;
        Info_BankAccount *temp;
        string Name, Account_number, Money;
        unsigned long moneyAccount,Balance,Cash;
        string Day,Month,Year,Hours,Minute,Second;
        int countStatment, coutBillBankclerk;
    public:
        BankAccount();
        bool login(string username,string password);
        void AddStatementBill(string name,string accountNumber,string money,string date,string time);//add data in node
        void AddStatementBillBankclerk(string type,string money,string date,string time);//add data in node statementBill by Bankclerk
        //name of customer
        void setName();
        //set balance money of account customer
        void setBalance();
        //set data for deposit
        void setData_deposit(string account,unsigned long int money);
        //check account number it's have data bank if have return true
        bool CheckAccount(string Account);
        /* menu of tranfer */
        bool CheckTransfer_account(string accountNumber);
        /* menu of withdraw */
        void Withdraw(unsigned long int withdraw);
        unsigned long getMoney();
        /* method for menu deposit */
        //add money to account of customer
        void AddMoney();
        //update money after deposit to in file BankAccount
        void updateMoney_to_BankAccount();
        // save history of deposit 
        //void saveStatement_deposit();
        // print bill for deposit
        void printBill_of_deposit(string amount);
        unsigned long int getMoneyAccount(string username);
        string setDateandTime();
        void payBill(string type,string group, string accountNumber, long double amount);
        void WriteStatement();    
        void WriteStatementBankclerk();
};
#endif