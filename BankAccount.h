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
        BankAccount *Obj_BankAccount;
        Info_BankAccount *temp;
        string Name;
        string Account_number;
        string Money;
        unsigned long Balance,Cash;
        string Day,Month,Year,Hours,Minute,Second;
    public:
        BankAccount();
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
        double getMoney();
        /* method for menu deposit */
        //add money to account of customer
        void AddMoney();
        //update money after deposit to in file BankAccount
        void updateMoney_to_BankAccount();
        // save history of deposit 
        //void saveStatement_deposit();
        // print bill for deposit
        void printBill_of_deposit(string amount);
};
#endif