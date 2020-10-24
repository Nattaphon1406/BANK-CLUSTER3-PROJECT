#ifndef BANKCLERK_H
#define BANKCLERK_H
#include <iostream>
#include <string>
#include "Information.h"
using namespace std;
class BankClerk : public Information{
    private:
        string Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password;
        int Choice;
    public:
        bool login(string username,string password);
        void AddName();
        void AddCitizenID();
        void AddBirthDate();
        void AddPhoneNumber();
        void AddClerkID();
        void AddPassword();
        void Registercustomer();
        void MenuMenageRegister(int Number);
};
#endif