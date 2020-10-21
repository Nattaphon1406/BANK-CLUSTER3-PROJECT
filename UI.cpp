#include "UI.h"
UI::UI(){
    obj_Info = new Information();
    Obj_Customer = NULL;
    username = " ";
    password = "";
    accountNumber = "";
    name = "";
    citizenID = "";
    birthDate = "";
    phoneNumber = "";
    money = 0;
}
UI::~UI(){
    obj_Info = NULL;
}
void UI::print_MainMenu(){
    cout << "========= MENU LOGIN =========" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "===============================" << endl;
}
void UI::print_Login(){
    cout << "============ Login ============" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "===============================" << endl;
}
void UI::printmenuRegister_customer(int Id){
    cout << "====== Register Customer ======" << endl;
    cout << "Name: ";
    cin >> username;
    cout << "CitizenID: ";
    cin >> citizenID;
    cout << "BirthDate: ";
    cin >> birthDate;
    cout << "Tel: ";
    cin >> phoneNumber;
    cout << "========= TypeAccount =========" << endl;
    cout << "1.DepositAccount ";
    cout << "2.SavingAccount";
    cin >> TypeAccount;
    cout << "===============================" << endl;
    if(TypeAccount == "1"){
        
    }
    else{
        
    }
}
void UI::printmenuRegister_bankClerk(){
    cout << "====== Register BankClerk =====" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "CitizenID: ";
    cin >> citizenID;
    cout << "BirthDate: ";
    cin >> birthDate;
    cout << "Tel: ";
    cin >> phoneNumber;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "===============================" << endl;
}
void UI::print_menuClerk{
    cout << "==================== MENU ====================" << endl;
    cout << "1. Deposition" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Pay Bill" << endl;
    cout << "5. Money Exchange" << endl;
    cout << "6. Statement" << endl;
    cout << "==============================================" << endl;
}
void UI::print_menuCustomer(){
    cout << "==================== MENU ====================" << endl;
    cout << "1. Transfer" << endl;
    cout << "2. Pay Bill" << endl;
    cout << "3. Statement" << endl;
    cout << "==============================================" << endl;
}
void UI::print_menuDeposit(Information deposit){
    cout << "==================== Deposition ==================== " << endl;
    cout << "Enter Account number: ";
    cin >> accountNumber;
        //check account number though BankAccount
}
