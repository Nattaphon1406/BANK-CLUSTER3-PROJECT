#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Information.h"
using namespace std;
class Customer : public Information{
    private:
        Customer *Obj_Customer;
        //Save Info Of Customer
    public:
        bool login(string username,string password);
};
#endif