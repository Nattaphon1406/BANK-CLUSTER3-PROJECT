#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
using namespace std;
class Customer{
    private:
        string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money;
    public:
        Customer();
        void SetInfoCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money);
        string getName();
        string getCitizenID();
        string getBirthDate();
        string getPhoneNumber();
        string getTypeAccount();
        string getMoney();
        //Save Info Of Customer
};
#endif