#include <iostream>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
using namespace std;
int main(){
    Information *Obj_Info = new Information();
    Obj_Info->LoadFileRegisterCustomer();
    Obj_Info->Show();
    return 0;
}