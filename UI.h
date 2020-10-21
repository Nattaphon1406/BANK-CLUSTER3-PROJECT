#ifndef UI_H
#define UI_H
#include <iostream>
#include "Information.h"
using namespace std;
class UI
{
    private:
        string username,password,accountNumber,name,citizenID,birthDate,phoneNumber;
        int money;
        Information *Obj_Info = new Information();
        Customer Obj_Customer;
    public:
    UI();
    ~UI();
    void print_MainMenu();
    void print_Login();
    void print_menuClerk();
    void print_menuCustomer();
    void printmenuRegister_customer();
    void printmenuRegister_bankClerk();
};
#endif
