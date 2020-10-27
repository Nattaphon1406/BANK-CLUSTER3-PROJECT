#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <sstream>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
#include <time.h>
#include <fstream>
using namespace std;
class BankAccount : public Information{
    private:
        class statementBill{
            public:
                string Name,AccountNumber,Type,Money,Date,Time;
                statementBill *linkBill;
                statementBill(string name,string accountNumber,string type,string money,string date,string time);
        };
        class statementBillBankclerk{
            public:
                string Type,Money,Date,Time;
                statementBillBankclerk *linkBillBankclerk;
                statementBillBankclerk(string type,string money,string date,string time);
        };
        class statementDeposit{
            public:
                string Name,AccountNumber,Money,Date,Time,Balance;
                statementDeposit *link;
                statementDeposit(string name,string accountNumber,string money,string balance,string date,string time);
        };
        class statementWithdraw{
            public:
                string Name,AccountNumber,Money,Date,Time,Balance;
                statementWithdraw *Withdrawlink;
                statementWithdraw(string name,string accountNumber,string money,string balance,string date,string time);
        };
        statementWithdraw *Withdrawhead,*Withdrawtail,*Withtemp;
        statementBill *headBill, *tailBill, *tempBill;
        statementBillBankclerk *headBillBankclerk, *tailBillBankclerk, *tempBillBankclerk;
        BankAccount *Obj_BankAccount;
        Info_BankAccount *temp;
        statementDeposit *head_deposit,*tail_deposit;
        string Name, Account_number, Money;
        unsigned long moneyAccount,Balance,Cash;
        string Day,Month,Year,Hours,Minute,Second;
        int countStatment, coutBillBankclerk,count_deposit;
    public:
        BankAccount();
        void AddStatementWithdraw(string name,string accountNumber,string money,string balance,string date,string time);
        bool login(string username,string password);
        //add data in node
        void AddStatementBillCustoment(string name,string accountNumber,string type,string money,string date,string time);//add data in node by cudtomer
        //add data in node statementBill by Bankclerk
        void AddStatementBillBankclerk(string type,string money,string date,string time);
        //Add data deposition
        void AddStatementBill_deposit(string name,string account,string money,string balance,string date,string time);
        //name of customer
        void setName();
        //set balance money of account customer
        void setBalance();
        //set data for deposit
        string getBalance(string Account);
        //return data for use in moneyExchenge
        void setData_deposit(string account,unsigned long int money);
        //check account number it's have data bank if have return true
        bool CheckAccount(string Account);
        /* menu of tranfer */
        bool CheckTransfer_account(string accountNumber);
        /* menu of withdraw */
        bool CheckUser(string user);
        // check user customer or bankclerk
        void Withdraw(unsigned long int withdraw);
        unsigned long getMoney();
        string getName();
        void WithdrawBill(int withdraw);
        void WriteStatementWithdraw();
        /* method for menu deposit */
        //add money to account of customer
        void AddMoney();
        //update money after deposit to in file BankAccount
        void updateMoney_to_BankAccount();
        // save history of deposit 
        void updateExchangeMoney_to_BankAccount(string Balance,string Account);
        // save balance from Exchange money to BankAccount file
        void WriteStatement_deposit();
        // print bill for deposit
        void printBill_of_deposit(string amount);
        unsigned long int getMoneyAccount(string username);
        string setDateandTime();
        void payBill(string type,string group, long double amount);
        void WriteStatementCustomer(string filename,string nameAc,string accountNumber,string TypeBill,string Amount,string date,string time);   
        void WriteStatementBankclerk(string filename,string TypeBill,string Amount,string date,string time);
        bool CheckTransfer_DeductMoneyBankclerk(int money,string accountNumber);
        // Update money in file 
        bool CheckTransfer_DeductMoneyCustomer(int money,string username);
        // Update money in file
        string getname_TransferorBC(string accountNumber);
        string getname_TransferorCT(string username);
        string getname_recipient(string Recipient_account);
        string getmoneyBC(string accountNumber);
        string getmoneyCT(string username);
        string getAccountNumber(string username);
        string getDateandTimeTransfer();
        bool Check_RecipientAccount(string Recipient_account);
        bool CheckTransfer_AddMoney(int money,string Recipient_account);
        // Add money to the recipient account
        bool CheckTransfer_AccountMoneyCustomer(int money,string accountNumber);
        // Checking account funds
        bool CheckTransfer_DeductMoneyBankOtherBC(int money,string accountNumber);
        // Update money in file
        bool CheckTransfer_DeductMoneyBankOtherCT(int money,string username);
        // Update money in file
        bool CheckTransfer_Account(string accountNumber);
        // Make sure you have information in file Bankaccout
        bool CheckTransfer_AccountMoneyBankClerk(int money,string accountNumber);
        // Checking account funds
        void statementTransfer_customer(string transferor,string recipient,string money_file,string Service_charge,string date);
        // Write history to file
        bool CheckTransfer_AccountMoneyCustomerOther(int money,string username);
        // Checking account funds
        bool CheckTransfer_AccountMoneyBankClerkOther(int money,string accountNumber);
        // Checking account funds
        bool CheckTransfer_AccountMoneyOther(string Recipient_account);
        // Checking account funds
};
#endif