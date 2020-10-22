#ifndef UI_H
#define UI_H
#include <iostream>
#include <sstream>
#include "Information.h"
using namespace std;
class UI{
    private:
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
