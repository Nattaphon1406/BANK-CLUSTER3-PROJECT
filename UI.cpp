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
void UI::print_Login(){
    cout << "============ Login ============" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "===============================" << endl;
}
void UI::print_Register(){
    cout << "=========== Register ==========" << endl;
    cout << "1. Register Customer" << endl;
    cout << "2. Register BankClerk" << endl;
    cout << "3. Back" << endl;
    cout << "===============================" << endl;
    cout << "Enter: ";
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
        Info_Customer.AddInfoRegisterCustomer(name,citizenID,birthDate,phoneNumber,"10",Money);
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
        Info_Customer.AddInfoRegisterCustomer(name,citizenID,birthDate,phoneNumber,"20",Money);
    }
    Info_Customer.SaveInfoRegisterCustomerToFile();
    cout << "===============================" << endl;
}
void UI::printmenuRegister_BankClerk(){
    Information Info_BankClerk;
    cout << "====== Register BankClerk =====" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin,name);
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
    Info_BankClerk.LoadFileBankClerk();
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
    Information Info_Customer;
    cout << "============ RegisterCustomerFile ============" << endl;
    cout << "No." << "\t" << "Name" << endl;
    cout << "==============================================" << endl;
    Info_Customer.ShowRegistercustomer();
    cout << "==============================================" << endl;
    cout << "Enter: ";
}
void UI::MenageRegister(int Number){
    Information Info_Customer;
    Info_Customer.LoadFileRegisterCustomer();
    int count;
    cout << "1.ConfirmRegister" << endl;
    cout << "2.RemoveRegister" << endl;
    cout << "Enter: " << endl;
    cin >> count;
    if(count == 1){
        Info_Customer.SaveInfoRegisterToFileBankAccount(Number);
        Info_Customer.RemoveInfoRegisterCustomer(Number);
        Info_Customer.SaveInfoRegisterCustomerToFile();
    }
    else if(count == 2){
        Info_Customer.RemoveInfoRegisterCustomer(Number); 
        Info_Customer.SaveInfoRegisterCustomerToFile();
    }
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
void UI::print_MoneyExchange(){
    int PaymentType,CurrencyType;
    float MoneyAmountForeign,MoneyAmountBaht;
    string AccountNumber;
    do{
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
        cout << "Enter Currency Type : ";	
        cin >> CurrencyType;

        if(CurrencyType != 7){
            cout << "Enter Money Amount(Foreign currency) : ";
            cin >> MoneyAmountForeign;

            do{
                cout << "------- Payment Type ------- " << endl;
                cout << "1. Cash " << endl;
                cout << "2. Bank Account " << endl;
                cout << "3. Return to choose new Currency or Exit" << endl;
                cout << "---------------------------- " << endl;                
                cout << "Enter Type of Payment : ";
                cin >> PaymentType;

                Obj_MoneyExchange.SetMoneyExchange(CurrencyType,MoneyAmountForeign,PaymentType);
                Obj_MoneyExchange.ExchangeCalculate(CurrencyType);

                if(PaymentType == 1){
                    Obj_MoneyExchange.ShowPaymentMoney();
                    cout << endl;
                    cout << "---------- Cash ------------ " << endl;
                    cout << "Enter Money Amount(Baht) : ";
                    cin >> MoneyAmountBaht;            
                    cout << "---------------------------- " << endl;

                    Obj_MoneyExchange.ShowBillCash(MoneyAmountBaht);
                }
                else if(PaymentType == 2){
                    cout << endl;
                    cout << "------- Bank Account ------- " << endl;
                    cout << "Enter Account Number : ";
                    cin >> AccountNumber;            
                    cout << "---------------------------- " << endl;

                    Obj_MoneyExchange.SetAccount(AccountNumber);
                    if(!Obj_MoneyExchange.CheckAccount()){
                       
                    }
                    else if(Obj_MoneyExchange.CheckAccount()){
                        cout <<"Yes" <<endl;
                    }

                } 
            }while(PaymentType != 3); //check menu PaymentType
            cout << "================================== " << endl;
        }// if check CurrencyType
    }while(CurrencyType != 7);//check menu CurrencyType
}
void UI :: Withdraw(){
    string Account;
    unsigned long int withdraw;
    Obj_BankAccount.LoadFileBankAccount();
    //Obj_BankAccount.ShowBankAccount();
    do{
        cout<<"=================== Withdraw ======================"<<endl
            <<"Enter Account Number: ";
        cin>>Account;
       // Obj_BankAccount.CheckAccount(Account);
    }while(!Obj_BankAccount.CheckAccount(Account));
    
    do{
        cout<<"Enter Withdraw Amount: ";
    cin>>withdraw;
    }while (withdraw%100!=0 || withdraw<100 || withdraw>Obj_BankAccount.getMoney());
    Obj_BankAccount.Withdraw(withdraw);
    Obj_BankAccount.SaveInfoCustomerToFile();
}
void UI::print_getDeposit(){
    bool check_account;
    Obj_BankAccount.LoadFileBankAccount();
    do{
        cout << "============================== Deposition ==============================" << endl;
        cout << "Please enter account number" << endl;
        cout << "Enter: ";
        cin >> accountNumber;
        cout << "money amount of deposition" << endl;
        cout << "Enter: ";
        cin >> money;
        cout << "=======================================================================" << endl;
        Obj_BankAccount.setData_deposit(accountNumber,money);
        check_account = Obj_BankAccount.CheckAccount(accountNumber);
        if(check_account == true)
        {
            system("cls");
            cout << "*** Account number correct *** " << endl;
            if(accountNumber[0] == '1'){
                cout << "Type account: Savings account" << endl;
                do{
                    if(money > 0){
                        Obj_BankAccount.AddMoney(); 
                    }
                    else{
                        system("cls");
                        cout << "amount of deposition incoorect!!" << endl;
                        cout << "money amount of deposition" << endl;
                        cout << "Enter: ";
                            cin >> money;
                    }
                }while(money == 0);
            }
            else if(accountNumber[0] == '2'){
                cout << "Type account: fixed deposit account" << endl;
                do{
                    if(money == 30000){
                        Obj_BankAccount.AddMoney();
                    }
                    else{
                        system("cls");
                        cout << "amount of deposition incoorect!!" << endl;
                        cout << "money amount of deposition" << endl;
                        cout << "Enter: ";
                        cin >> money;
                    }
                }while(money != 30000);
            }
        }
        else{
            system("cls");
            cout << "*** Data not found!! ***" << endl;
            cout << "Please do the deposition list again" << endl;
        }
    }while(check_account != true);
}