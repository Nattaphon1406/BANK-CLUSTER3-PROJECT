#include <iostream>
#include "Information.h"
#include "UI.h"
#include "MoneyExchange.h"
using namespace std;
int main(){
    string Number;
    int Choice;
    UI Obj_UI;
    MainMenu:
        Obj_UI.print_MainMenu();
        cin >> Choice;
        if(Choice == 1){
            Obj_UI.print_Login();
            if(Obj_UI.Checklogin() == 1){
                Obj_UI.print_menuCustomer();
                cin >> Choice;
                if(Choice == 1){ //Transfer
                    Obj_UI.transfer_firstPage();
                }
                else if(Choice == 2){//Pay Bill
                    Obj_UI.PayBill();
                }
                else if(Choice == 3){//Statement 
                    
                }
                goto MainMenu;
            }
            else if(Obj_UI.Checklogin() == 2){
                    ClerkMemu:
                    Obj_UI.print_menuClerk();
                    cin >> Choice;
                    if(Choice == 1){ //Deposition
                        Obj_UI.print_getDeposit();
                    }
                    else if(Choice == 2){ //Withdraw
                        Obj_UI.Withdraw();
                    }
                    else if(Choice == 3){ //Transfer
                        Obj_UI.transfer_firstPage();
                    }
                    else if(Choice == 4){ //Pay Bill
                        Obj_UI.PayBill();
                    }
                    else if(Choice == 5){ //Money Exchange
                        Obj_UI.print_MoneyExchange();
                    }else if(Choice == 6){ //Statement
                        
                    }
                    else if(Choice == 7){ //MenageRegister
                        Obj_UI.printInfoFromFileRegister();
                        cin >> Choice;
                        Obj_UI.MenageRegister(Choice);
                    }
                    else if(Choice == 8){
                        goto MainMenu;
                    }
                    goto ClerkMemu;
            }
            else{
                cout << "!!!!!Invalid Username or Password!!!!" << endl;
                goto MainMenu;
            }
        }
        else if(Choice == 2){
            Obj_UI.print_Register();
            cin >> Choice;
            if(Choice == 1){
                Obj_UI.printmenuRegister_Customer();
            }
            else if(Choice == 2){
                Obj_UI.printmenuRegister_BankClerk();
            }
            goto MainMenu;
        }
        else{
            return 0;
        }

    return 0;
}