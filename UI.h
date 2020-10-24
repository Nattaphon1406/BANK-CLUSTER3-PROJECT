#ifndef UI_H
#define UI_H
#include <iostream>
#include <sstream>
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
using namespace std;
class UI{
    private:
        Customer Obj_Customer;
        BankClerk Obj_BankClerk;
        BankAccount Obj_BankAccount;
        string username,password,accountNumber,name,citizenID,birthDate,phoneNumber,typeAccount;
        int money;
    public:
        UI();
        ~UI();
        void print_MainMenu();
        void print_Login();
        void print_Register();
        void SvaeRegisterCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,int money);
        void SaveRegisterBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password);
        void SaveInfoCustomerToBankAccount(string name,string accountNumber,string money,string username,string password);
        int Checklogin();
        //It has Funtion Check Username and Password
        void print_menuClerk();
        void print_menuCustomer();
        void printmenuRegister_Customer();
        void printmenuRegister_BankClerk();
        void printInfoFromFileRegister();
        void MenageRegister(int Number);
        void print_CurrencyType();
        void print_PaymentType();
        void transfer_firstPage();
};
#endif
