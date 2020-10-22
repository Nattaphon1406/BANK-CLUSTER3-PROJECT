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
    cout << "========= MENU LOGIN =========" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "===============================" << endl;
    cout << "Enter: "; 
}
void UI::print_Login(){
    cout << "============ Login ============" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "===============================" << endl;
    //It has Funtion Check Username and Password
}
void UI::printmenuRegister_customer(){
    Information Info_Customer;
    stringstream ss;
    string Money;
    cout << "====== Register Customer ======" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin,name);
    cout << "CitizenID: ";
    cin >> citizenID;
    cout << "BirthDate: ";
    cin >> birthDate;
    cout << "Tel: ";
    cin >> phoneNumber;
    cout << "========= TypeAccount =========" << endl;
    cout << "1. DepositAccount [  500 Bath]" << endl;
    cout << "2. SavingAccount  [20000 Bath]" << endl;
    cout << "TypeAccount: ";
    cin >> typeAccount;
    Info_Customer.LoadFileRegisterCustomer();
    Info_Customer.ShowRegistercustomer();
    if(typeAccount == "1"){
        EnterMoneyDepositAccount:
        cout << "Money: ";
        cin >> money;
        if(money < 500){
            goto EnterMoneyDepositAccount;
        }
        ss << money;
        ss >> Money;
        ss.clear();
        Info_Customer.ShowRegistercustomer();
        Info_Customer.AddInfoRegisterCustomer(name,citizenID,birthDate,phoneNumber,"10",Money);
        Info_Customer.ShowRegistercustomer();
    }
    else{
        EnterMoneySavingAccount:
        cout << "Money: ";
        cin >> money;
        if(money < 20000){
            goto EnterMoneySavingAccount;
        }
        ss << money;
        ss >> Money;
        ss.clear();
        Info_Customer.ShowRegistercustomer();
        Info_Customer.AddInfoRegisterCustomer(name,citizenID,birthDate,phoneNumber,"20",Money);
        Info_Customer.ShowRegistercustomer();
    }
    Info_Customer.ShowRegistercustomer();
    Info_Customer.SaveInfoRegisterCustomerToFile();
    cout << "===============================" << endl;
}
void UI::printmenuRegister_bankClerk(){
    Information Info_BankClerk;
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
    Info_BankClerk.AddInfoBankClerk(name,citizenID,birthDate,phoneNumber,username,password);
    Info_BankClerk.SaveInfoBankClerkToFile();
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
    cout << "8. Return to Login" << endl;
    cout << "==============================================" << endl;
    
}
void UI::print_menuCustomer(){
    cout << "==================== MENU ====================" << endl;
    cout << "1. Transfer" << endl;
    cout << "2. Pay Bill" << endl;
    cout << "3. Statement" << endl;
    cout << "==============================================" << endl;
}
void UI::printInfoFromFileRegister(){
    Information Info_Customer;
    cout << "============ RegisterCustomerFile ============" << endl;
    cout << "No." << "\t" << "Name" << endl;
    cout << "==============================================" << endl;
    Info_Customer.ShowRegistercustomer();
    cout << "==============================================" << endl;
}
void UI::MenageRegister(int Number){
    Information Info_Customer;
    int count;
    cout << "1.ConfirmRegister" << endl;
    cout << "2.RemoveRegister" << endl;
    cout << "Enter: " << endl;
    cin >> count;
    if(count == 1){
        Info_Customer.SaveInfoCustomerToFile();
    }
    else if(count == 2){
        Info_Customer.RemoveInfoRegisterCustomer(Number); 
    }
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
}
void UI::print_PaymentType(){
    cout << "------- Payment Type ------- " << endl;
	cout << "1. Cash " << endl;
	cout << "2. Bank Account " << endl;
	cout << "3. Return to choose new Currency or Exit" << endl;
	cout << "---------------------------- " << endl;
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