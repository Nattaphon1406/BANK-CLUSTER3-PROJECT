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
    Recipient_account = "";
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
void UI::PayBill(){
    Obj_BankAccount.LoadFileBankAccount();
    string type,chooseGroup, user;
    unsigned long int amount,checkMoney, getMoney;
    int temp;
    cout << "=========AccoutNumber=========" << endl;
	cout << "Input account : ";
	cin >> accountNumber;
    temp = Obj_BankAccount.CheckAccount(accountNumber);
    if(temp==true){
        type = "customer";
        do{
            cout << "===================Customer====================" << endl << endl;
            cout << "===================GroupBill===================" << endl;
            cout << "1.Water bill" << endl;
            cout << "2.Electricity bill" << endl;
            cout << "3.Phone bill" << endl;
            cout << "===============================================" << endl;	
            cout << "Enter: ";
            cin >> chooseGroup;
        }while(chooseGroup!="1"&&chooseGroup!="2"&&chooseGroup!="3");
        cout << "Amount to pay the bill: ";
        cin >> amount;
        
        getMoney=Obj_BankAccount.getMoney();//get money in Account
        //Check whether the amount is enough to include the fee.
        if(chooseGroup=="1"){
            checkMoney = amount*0.3;
            checkMoney += amount;
            //More money in the account
            cout << getMoney<< " " << checkMoney << endl;
            if(getMoney>checkMoney){
                Obj_BankAccount.payBill(type,chooseGroup,accountNumber,amount);
            }
            else{
                cout << "The amount is not enough" << endl;
            }
        }
        else if(chooseGroup=="2"){
            checkMoney = amount*0.4;
            checkMoney += amount;
            //More money in the account
            cout << getMoney<< " " << checkMoney << endl;
            if(getMoney>checkMoney){
                Obj_BankAccount.payBill(type,chooseGroup,accountNumber,amount);
            }
            else{
                cout << "The amount is not enough" << endl;
            }
        }
        else if(chooseGroup=="3"){
            checkMoney = amount*0.5;
            checkMoney += amount;
            //More money in the account
            cout << "Get: "<< getMoney<< " " << checkMoney << endl;
            if(getMoney>checkMoney){
                Obj_BankAccount.payBill(type,chooseGroup,accountNumber,amount);
            }
            else{
                cout << "The amount is not enough" << endl;
            }
        }
    }
    else{
        type = "Bankclerk";
        do{
            cout << "===================Bankclerkr==================" << endl << endl;
            cout << "===================GroupBill===================" << endl;
            cout << "1.Water bill" << endl;
            cout << "2.Electricity bill" << endl;
            cout << "3.Phone bill" << endl;
            cout << "===============================================" << endl;	
            cout << "Enter: ";
            cin >> chooseGroup;
        }while(chooseGroup!="1"&&chooseGroup!="2"&&chooseGroup!="3");
        cout << "Amount to pay the bill: ";
        cin >> amount;
    }
}
void UI::transfer_firstPage(){
    Obj_BankAccount.LoadFileBankAccount();
    back1:
    cout << "=========Transfer=========" << endl;
    back:
	cout << "Transferor account : ";
	cin >> accountNumber;
    if(Obj_BankAccount.CheckTransfer_Account(accountNumber) == true){
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
bool UI::NotEnough_moneyBankClerk(){
    if((Obj_BankAccount.CheckTransfer_AccountMoneyBankClerk(money,accountNumber) == false)){
        return true;
    }    
}
void UI::Ready_transfer(){
    cout << "===========================" << endl;
	cout << "Ready to transfer" << endl;
	cout << "1.Confirm" << endl;
	cout << "2.Modify"<< endl;
	cout << "3.Cancal"<< endl;
	cout << "===========================" << endl;
	cout << "Enter : ";
}
void UI::Bill_BankClerk(){
    if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == true){
        Obj_BankAccount.CheckTransfer_DeductMoneyBankclerk(money,accountNumber);
        Obj_BankAccount.CheckTransfer_AddMoney(money,Recipient_account);
        cout << "======================Success=======================" << endl;
        cout << "   Form                                             " << endl;
        cout << "      name : " << Obj_BankAccount.getname_TransferorBC(accountNumber) << endl;
        cout << "      Account number : " << accountNumber << endl;
        cout << "   To                                               " << endl;
        cout << "      name : " << Obj_BankAccount.getname_recipient(Recipient_account) << endl;
        cout << "      Account number : " << Recipient_account << endl;
        cout << "  ------------------------------------------------  " << endl;
        cout << "   Amount : " << money << endl;
        cout << "   Service charge : " << "0" << endl;
        cout << "   Balance : " << Obj_BankAccount.getmoneyBC(accountNumber) << endl;
        cout << "   Transaction date : " << Obj_BankAccount.setDateandTimeTransfer() << endl;
        cout << "====================================================" << endl;
    }
    else if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == false){
        Obj_BankAccount.CheckTransfer_DeductMoneyBankOtherBC(money,accountNumber);
        cout << "======================Success=======================" << endl;
        cout << "   Form                                             " << endl;
        cout << "      name : " << Obj_BankAccount.getname_TransferorBC(accountNumber) << endl;
        cout << "      Account number : " << accountNumber << endl;
        cout << "   To                                               " << endl;
        cout << "      name : " << "-" << endl;
        cout << "      Account number : " << Recipient_account << endl;
        cout << "  ------------------------------------------------  " << endl;
        cout << "   Amount : " << money << endl;
        cout << "   Service charge : " << "10" << endl;
        cout << "   Balance : " << Obj_BankAccount.getmoneyBC(accountNumber) << endl;
        cout << "   Transaction date : " << Obj_BankAccount.setDateandTimeTransfer() << endl;
        cout << "====================================================" << endl;
    }
}
void UI::transfer_FirstPage(){
    Obj_BankAccount.LoadFileBankAccount();
    back1:
    cout << "=========Transfer=========" << endl;
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
bool UI::NotEnough_moneyCustomer(){
    if((Obj_BankAccount.CheckTransfer_AccountMoneyCustomer(money,username) == false)){
        cout << "======Not enough money======" << endl;
        return true;
    }    
}
void UI::Bill_Customer(){
    if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == true){
        Obj_BankAccount.CheckTransfer_DeductMoneyCustomer(money,username);
        Obj_BankAccount.CheckTransfer_AddMoney(money,Recipient_account);
        cout << "======================Success=======================" << endl;
        cout << "   Form                                             " << endl;
        cout << "      name : " << Obj_BankAccount.getname_TransferorCT(username) << endl;
        cout << "      Account number : " << Obj_BankAccount.getAccountNumber(username) << endl;
        cout << "   To                                               " << endl;
        cout << "      name : " << Obj_BankAccount.getname_recipient(Recipient_account) << endl;
        cout << "      Account number : " << Recipient_account << endl;
        cout << "  ------------------------------------------------  " << endl;
        cout << "   Amount : " << money << endl;
        cout << "   Service charge : " << "0" << endl;
        cout << "   Balance : " << Obj_BankAccount.getmoneyCT(username) << endl;
        cout << "   Transaction date : " << Obj_BankAccount.setDateandTimeTransfer() << endl;
        cout << "====================================================" << endl;
    }
    else if(Obj_BankAccount.Check_RecipientAccount(Recipient_account) == false){
        Obj_BankAccount.CheckTransfer_DeductMoneyBankOtherCT(money,username);
        cout << "======================Success=======================" << endl;
        cout << "   Form                                             " << endl;
        cout << "      name : " << Obj_BankAccount.getname_TransferorCT(username) << endl;
        cout << "      Account number : " << Obj_BankAccount.getAccountNumber(username) << endl;
        cout << "   To                                               " << endl;
        cout << "      name : " << "-" << endl;
        cout << "      Account number : " << Recipient_account << endl;
        cout << "  ------------------------------------------------  " << endl;
        cout << "   Amount : " << money << endl;
        cout << "   Service charge : " << "10" << endl;
        cout << "   Balance : " << Obj_BankAccount.getmoneyCT(username) << endl;
        cout << "   Transaction date : " << Obj_BankAccount.setDateandTimeTransfer() << endl;
        cout << "====================================================" << endl;
    }
}
