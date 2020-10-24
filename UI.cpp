#include "UI.h"
UI::UI(){
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
    username = " ";
    password = "";
    accountNumber = "";
    name = "";
    citizenID = "";
    birthDate = "";
    phoneNumber = "";
    money = 0;
}
void UI::print_MainMenu(){
    cout << "============ Menu ============" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "===============================" << endl;
    cout << "Enter: "; 
}
void UI::print_Register(){
    cout << "=========== Register ==========" << endl;
    cout << "1. Register Customer" << endl;
    cout << "2. Register BankClerk" << endl;
    cout << "3. Back" << endl;
    cout << "===============================" << endl;
    cout << "Enter: ";
}
void UI::print_Login(){
    cout << "============ Menu ============" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "===============================" << endl;
}
int UI::Checklogin(){
    if(Obj_Customer.login(username,password)){
        return 1;
    }
    else if(Obj_BankClerk.login(username,password)){
        return 2;
    }
    //It has Funtion Check Username and Password
    return 3;
}
void UI::printmenuRegister_Customer(){
    cout << "====== Register Customer ======" << endl;
    cout << "Name: ";
    Obj_Customer.AddName();
    cout << "CitizenID: ";
    Obj_Customer.AddCitizenID();
    cout << "BirthDate: ";
    Obj_Customer.AddBirthDate();
    cout << "Tel: ";
    Obj_Customer.AddPhoneNumber();
    cout << "========= TypeAccount =========" << endl;
    cout << "1. DepositAccount [  500 Bath]" << endl;
    cout << "2. SavingAccount  [20000 Bath]" << endl;
    cout << "===============================" << endl;
    cout << "TypeAccount: ";
    Obj_Customer.AddTypeAccount();
    if(Obj_Customer.AddMoney()){
        Obj_Customer.Registercustomer();
    }
    cout << "===============================" << endl;
}
void UI::printmenuRegister_BankClerk(){
    cout << "====== Register BankClerk =====" << endl;
    cout << "Name: ";
    Obj_BankClerk.AddName();
    cout << "CitizenID: ";
    Obj_BankClerk.AddCitizenID();
    cout << "BirthDate: ";
    Obj_BankClerk.AddBirthDate();
    cout << "Tel: ";
    Obj_BankClerk.AddPhoneNumber();
    cout << "Username: ";
    Obj_BankClerk.AddClerkID();
    cout << "Password: ";
    Obj_BankClerk.AddPassword();
    Obj_BankClerk.Registercustomer();
    cout << "===============================" << endl;
}
void UI::print_menuClerk(){
    cout << "==================== MENU ====================" << endl;
    cout << "1. Deposition" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Pay Bill" << endl;
    cout << "5. Money Exchange" << endl;
    cout << "6. Statement" << endl;
    cout << "7. MenageRegister" << endl;
    cout << "8. Logout" << endl;
    cout << "==============================================" << endl;
    cout << "Enter: ";
}
void UI::print_menuCustomer(){
    cout << "==================== MENU ====================" << endl;
    cout << "1. Transfer" << endl;
    cout << "2. Pay Bill" << endl;
    cout << "3. Statement" << endl;
    cout << "4. Logout" << endl;
    cout << "==============================================" << endl;
    cout << "Enter: ";
}
void UI::printInfoFromFileRegister(){
    Obj_Customer.LoadFileRegisterCustomer();
    cout << "============ RegisterCustomerFile ============" << endl;
    cout << "No." << "\t" << "Name" << endl;
    cout << "==============================================" << endl;
    Obj_Customer.ShowRegistercustomer();
    cout << "==============================================" << endl;
    cout << "Enter: ";
}
void UI::MenageRegister(int Number){
    cout << "1.ConfirmRegister" << endl;
    cout << "2.RemoveRegister" << endl;
    cout << "Enter: ";
    Obj_BankClerk.MenuMenageRegister(Number);
}
void UI::print_CurrencyType(){
    cout << "========= Money Exchange ========= " << endl;
	cout << "------- Foreign Currency -------" << endl;
	cout << "1. JPY(Yen)" << endl;
	cout << "2. USD(Dollar)" << endl;
	cout << "3. CNY(Yuan)" << endl;
	cout << "4. KRW(Won)" << endl;
	cout << "5. GBR(Pound)" << endl;
	cout << "6. EUR(Euro)" << endl;
	cout << "7. EXIT " << endl;
	cout << "---------------------------- " << endl;
    cout << "Enter: ";
}
void UI::print_PaymentType(){
    cout << "------- Payment Type ------- " << endl;
	cout << "1. Cash " << endl;
	cout << "2. Bank Account " << endl;
	cout << "3. Return to choose new Currency or Exit" << endl;
	cout << "---------------------------- " << endl;
    cout << "Enter: ";
}
void UI::transfer_firstPage(){
    Obj_BankAccount.LoadFileBankAccount();
    string Recipient_account;
    back:
    cout << "=========Transfer=========" << endl;
	cout << "Transferor account : ";
	cin >> accountNumber;
    if(Obj_BankAccount.CheckTransfer_account(accountNumber)){
        goto next;
    }
    else{
        goto back;
    }
    next:
	do{
		cout << "Recipient account : ";
		cin >> Recipient_account;
	}while(Recipient_account.length() != 10);
	do{
		cout << "Amount : ";
		cin >> money;
	}while(money > 50000);
	cout << "===========================" << endl;
}
void UI::SvaeRegisterCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,int money){
    Information Info_Customer;
    Info_Customer.LoadFileRegisterCustomer();
}
void UI::SaveRegisterBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password){
    Information Info_BankClerk;
    Info_BankClerk.LoadFileBankClerk();
}
void UI::SaveInfoCustomerToBankAccount(string name,string accountNumber,string money,string username,string password){
    Information Info_BankAccount;
    Info_BankAccount.LoadFileRegisterCustomer();
}