#include <iostream>
#include "Information.h"
#include "UI.h"
#include "MoneyExchange.h"
using namespace std;
int main(){
    string Number;
    int Choice;
    UI Obj_UI;
    MoneyExchange Obj_MoneyExchange;
    MainMenu:
        Obj_UI.print_MainMenu();
        cin >> Choice;
        if(Choice == 1){
            Obj_UI.print_Login();
            if(Obj_UI.Checklogin() == 1){
                cout << "Customer Menu" << endl;
                goto MainMenu;
            }
            else if(Obj_UI.Checklogin() == 2){
                do{
                    Obj_UI.print_menuClerk();
                    cin >> Choice;
                    if(Choice == 1){ //Deposition

                    }
                    else if(Choice == 2){ //Withdraw

                    }
                    else if(Choice == 3){ //Transfer
                        Obj_UI.transfer_firstPage();
                    }
                    else if(Choice == 4){ //Pay Bill
                        
                    }
                    else if(Choice == 5){ //Money Exchange
                        int PaymentType,CurrencyType;
                        float MoneyAmountForeign,MoneyAmountBaht;
                        string AccountNumber;
                        do{
                            Obj_UI.print_CurrencyType();
                            cout << " Currency Type : ";	
                            cin >> CurrencyType;
                            if(CurrencyType != 7){
                                cout << " Money Amount(Foreign currency) : ";
                                cin >> MoneyAmountForeign;

                                do{
                                    Obj_UI.print_PaymentType();
                                    cout << " Type of Payment : ";
                                    cin >> PaymentType;

                                    Obj_MoneyExchange.SetMoneyExchange(CurrencyType,MoneyAmountForeign,PaymentType);
                                    Obj_MoneyExchange.ExchangeCalculate(CurrencyType);

                                    if(PaymentType == 1){
                                        Obj_MoneyExchange.ShowPaymentMoney();
                                        cout << endl;
                                        cout << " ---------- Cash ------------ " << endl;
                                        cout << " Money Amount(Baht) : ";
                                        cin >> MoneyAmountBaht;
                                        
                                        cout << " ---------------------------- " << endl;

                                        Obj_MoneyExchange.ShowBillCash(MoneyAmountBaht);
                                    }
                                    else if(PaymentType == 2){
                                        cout << endl;
                                        cout << " ------- Bank Account ------- " << endl;
                                        cout << " Account Number : ";
                                        cin >> AccountNumber;
                                        
                                        cout << " ---------------------------- " << endl;
                                    } 
                                }while(PaymentType != 3); //check menu PaymentType
                                cout << " ================================== " << endl;
                            }// if check CurrencyType
                        }while(CurrencyType != 7); //check menu CurrencyType
                    }
                    else if(Choice == 6){ //Statement
                        
                    }
                    else if(Choice == 7){ //MenageRegister
                        Obj_UI.printInfoFromFileRegister();
                        cin >> Choice;
                        Obj_UI.MenageRegister(Choice);
                    }
                }while(Choice != 8); // check menu Clerk
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