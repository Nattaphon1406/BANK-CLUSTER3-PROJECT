#ifndef UI_H
#define UI_H
#include <iostream>
#include <sstream>
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
#include "MoneyExchange.h"
using namespace std;
class UI{
    private:
        Information Obj_Info;
        Customer Obj_Customer;
        BankClerk Obj_BankClerk;
        BankAccount Obj_BankAccount;
        MoneyExchange Obj_MoneyExchange;
        string username,password,accountNumber,name,citizenID,birthDate,phoneNumber,typeAccount,Recipient_account;
        unsigned long int money;
    public:
        UI();
        ~UI();
        void print_MainMenu();
        void print_Login();
        void print_Register();
        /*void SvaeRegisterCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,int money);
        void SaveRegisterBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password);
        void SaveInfoCustomerToBankAccount(string name,string accountNumber,string money,string username,string password);
        */int Checklogin();
        //It has Function Check Username and Password
        void print_menuClerk();
        void print_menuCustomer();
        void printmenuRegister_Customer();
        void printmenuRegister_BankClerk();
        void printInfoFromFileRegister();
        void MenageRegister(int Number);
        void RemoveBankAccount();
        bool transfer_firstPage();
        void print_MoneyExchange();
        void Withdraw();
        void print_getDeposit();
        void PayBill();
        void Ready_transfer();
        void Bill_BankClerk();
        void Bill_Customer();
        bool transfer_FirstPage();
        bool NotEnough_moneyCustomer();
        bool NotEnough_moneyBankClerk();
};
#endif
