#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
using namespace std;
class BankAccount{
    private:
        string Name,AccountNumber,Money,Username,Password;
    public:
        BankAccount();
        void SetInfoBankAccount(string name,string accountNumber,string money,string username,string password);
        string getName();
        string getAccountNumber();
        string getMoney();
        string getUsername();
        string getPassword();
        //Save Info Of BankAccount
};
#endif