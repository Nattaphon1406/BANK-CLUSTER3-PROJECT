#include <iostream>
#include "Information.h"
#include "Customer.h"
#include "BankClerk.h"
#include "BankAccount.h"
#include "UI.h"
using namespace std;
int main(){
    string Number;
    int Choice;
    Information *Obj_Info = new Information();
    UI Obj_UI;
    MainMenu:
    Obj_UI.print_MainMenu();
    cin >> Choice;
    if(Choice == 1){
        Obj_UI.print_Login();
        Obj_UI.print_menuClerk();
        cout << "Enter: ";
        cin >> Choice;
        if(Choice == 7){
            Obj_UI.printInfoFromFileRegister();
            cout << "Enter: ";
            cin >> Choice;
            Obj_UI.MenageRegister(Choice);
        }
        goto MainMenu;
    }
    else if(Choice == 2){
        Obj_Info->LoadFileRegisterCustomer();
        Obj_UI.printmenuRegister_customer();
        goto MainMenu;
    }
    return 0;
}