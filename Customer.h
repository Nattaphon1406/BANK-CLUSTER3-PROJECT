#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Information.h"
#include "BankAccount.h"
using namespace std;
class Customer : public Information{
    private:
        Customer *Obj_Customer;
        stringstream ss;
        string Name,CitizenID,BirthDate,PhoneNumber,money;
        int Money,TypeAccount;
        //Save Info Of Customer
    public:
        bool login(string username,string password);
        void AddName();
        void AddCitizenID();
        void AddBirthDate();
        void AddPhoneNumber();
        void AddTypeAccount();
        bool AddMoney();
        void Registercustomer();
};
#endif