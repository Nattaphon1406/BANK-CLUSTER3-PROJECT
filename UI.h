#ifndef UI_H
#define UI_H
#include <iostream>
#include <sstream>
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
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
        //It has Funtion Check Username and Password
        void print_menuClerk();
        void print_menuCustomer();
        void printmenuRegister_customer();
        void printmenuRegister_bankClerk();
        void printInfoFromFileRegister();
        void MenageRegister(int Number);
};
#endif
