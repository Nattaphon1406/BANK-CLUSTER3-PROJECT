#include "Information.h"
Information :: Info_Customer :: Info_Customer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money){
      SetInfoCustomer(name,citizenID,birthDate,phoneNumber,typeAccount,money);
      link = NULL;
}
Information :: Info_BankClerk :: Info_BankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password){
      SetInfoBankClerk(name,citizenID,birthDate,phoneNumber,clerkID,password);
      link = NULL;
}
Information :: Info_BankAccount :: Info_BankAccount(string name,string accountNumber,string money,string username,string password){
      SetInfoBankAccount(name,accountNumber,money,username,password);
      link = NULL;
}
Information :: Information(){
      HeadInfo_Customer = NULL;
      TailInfo_Customer = NULL;
      HeadInfo_BankClerk = NULL;
      TailInfo_BankClerk = NULL;
      HeadInfo_BankAccount = NULL;
      TailInfo_BankAccount = NULL;
      Count_Customer = 0;
      Count_BankClerk = 0;
      Count_BankAccount = 0;
}
Information :: ~Information(){
      for(int i=0;i<Count_Customer;i++){
            Info_Customer *Data_Customer = HeadInfo_Customer;
            HeadInfo_Customer = HeadInfo_Customer->link;
            delete Data_Customer;
            Data_Customer = NULL;
      }
      for(int i=0;i<Count_BankClerk;i++){
            Info_BankClerk *Data_BankClerk = HeadInfo_BankClerk;
            HeadInfo_BankClerk = HeadInfo_BankClerk->link;
            delete Data_BankClerk;
            Data_BankClerk = NULL;
      }
      for(int i=0;i<Count_BankAccount;i++){
            Info_BankAccount *Data_BankAccount = HeadInfo_BankAccount;
            HeadInfo_BankAccount = HeadInfo_BankAccount->link;
            delete Data_BankAccount;
            Data_BankAccount = NULL;
      }
      HeadInfo_Customer = NULL;
      TailInfo_Customer = NULL;
      HeadInfo_BankClerk = NULL;
      TailInfo_BankClerk = NULL;
      HeadInfo_BankAccount = NULL;
      TailInfo_BankAccount = NULL;
}
void Information :: LoadFileRegisterCustomer(){
      string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money,Line;
      ifstream Write;
      Count_Customer = 0;
      HeadInfo_Customer = NULL;
      TailInfo_Customer = NULL;
      Write.open("RegisterAccountCustomer.dat");
      if(Write.fail()){
        cout << "Can not Write File 'RegisterAccountCustomer.dat' " << endl;
      }
      else{
          while(getline(Write,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              CitizenID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              BirthDate = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              PhoneNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              TypeAccount = Line.substr(0,Line.find(','));
              Money = Line.erase(0,Line.find(',')+1);
              AddInfoRegisterCustomer(Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money);
          }
          Write.close();
      }
}
void Information :: LoadFileBankAccount(){
      string Name,AccountNumber,Money,Username,Password,Line;
      ifstream Write;
      Count_BankAccount = 0;
      HeadInfo_BankAccount = NULL;
      TailInfo_BankAccount = NULL;
      Write.open("BankAccount.dat");
      if(Write.fail()){
        cout << "Can not Write File 'BankAccount.dat' " << endl;
      }
      else{
          while(getline(Write,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              AccountNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Money = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Username = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Password = Line.erase(0,Line.find(',')+1);
              AddInfoBankAccount(Name,AccountNumber,Money,Username,Password);
          }
          Write.close();
      }
}
void Information :: LoadFileBankClerk(){
      string Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password,Line;
      ifstream Write;
      Count_Customer = 0;
      HeadInfo_Customer = NULL;
      TailInfo_Customer = NULL;
      Write.open("BankClerk.dat");
      if(Write.fail()){
        cout << "Can not Write File 'BankClerk.dat' " << endl;
      }
      else{
          while(getline(Write,Line)){
              Name = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              CitizenID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              BirthDate = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              PhoneNumber = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              ClerkID = Line.substr(0,Line.find(','));
              Line.erase(0,Line.find(',')+1);
              Password = Line.erase(0,Line.find(',')+1);
              AddInfoBankClerk(Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password);
          }
          Write.close();
      }
}
void Information :: AddInfoRegisterCustomer(string name,string citizenID,string birthDate,string phoneNumber,string typeAccount,string money){
      Info_Customer *newCustomer = new Info_Customer(name,citizenID,birthDate,phoneNumber,typeAccount,money);
            if(HeadInfo_Customer == NULL){
                HeadInfo_Customer = newCustomer;
                TailInfo_Customer = newCustomer;
            }
            else{
                TailInfo_Customer->link = newCustomer;
                TailInfo_Customer = newCustomer;
            }
            Count_Customer++;
}
void Information :: AddInfoBankClerk(string name,string citizenID,string birthDate,string phoneNumber,string clerkID,string password){
      Info_BankClerk *newBankAccount = new Info_BankClerk(name,citizenID,birthDate,phoneNumber,clerkID,password);
            if(HeadInfo_BankClerk == NULL){
                HeadInfo_BankClerk = newBankAccount;
                TailInfo_BankClerk = newBankAccount;
            }
            else{
                TailInfo_BankClerk->link = newBankAccount;
                TailInfo_BankClerk = newBankAccount;
            }
            Count_BankClerk++;
}
void Information :: AddInfoBankAccount(string name,string accountNumber,string money,string username,string password){
      Info_BankAccount *newBankClerk = new Info_BankAccount(name,accountNumber,money,username,password);
            if(HeadInfo_BankAccount == NULL){
                HeadInfo_BankAccount = newBankClerk;
                TailInfo_BankAccount = newBankClerk;
            }
            else{
                TailInfo_BankAccount->link = newBankClerk;
                TailInfo_BankAccount = newBankClerk;
            }
            Count_BankAccount++;
}
void Information :: RemoveInfoRegisterCustomer(int Number){
      Info_Customer *temp,*ptemp;
      temp = HeadInfo_Customer;
      for(int i = 1; i < Count_Customer; i++){
            if(i == Number){
                  if(i==1){
                        HeadInfo_Customer = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  Count_Customer--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: RemoveInfoBankAccount(string AccountNumber){
      Info_BankAccount *temp,*ptemp;
      temp = HeadInfo_BankAccount;
      for(Info_BankAccount *i = HeadInfo_BankAccount; i != NULL; i = i->link){
            if(i->getAccountNumber() == AccountNumber){
                  if(i == HeadInfo_BankAccount){
                        HeadInfo_BankAccount = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  Count_BankAccount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
      SaveInfoCustomerToFile();
}
void Information :: RemoveInfoBankClerk(int Number){
      Info_BankClerk *temp,*ptemp;
      temp = HeadInfo_BankClerk;
      for(int i = 1; i < Count_BankClerk; i++){
            if(i == Number){
                  if(i==1){
                        HeadInfo_BankClerk = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  Count_BankClerk--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: SaveInfoRegisterCustomerToFile(){
      ofstream Write("RegisterAccountCustomer.dat");
        if(Write){
            for(Info_Customer *i = HeadInfo_Customer; i != NULL; i = i->link){
                Write << i->getName() << "," << i->getCitizenID() << "," << i->getBirthDate() << "," << i->getPhoneNumber() << "," << i->getTypeAccount() << "," << i->getMoney() << endl;
            }
        }
      Write.close();
}
void Information :: SaveInfoCustomerToFile(){
      ofstream Write("BankAccount.dat");
        if(Write){
            for(Info_BankAccount *i = HeadInfo_BankAccount; i != NULL; i = i->link){
                Write << i->getName() << "," << i->getAccountNumber() << "," << i->getMoney() << "," << i->getUsername() << "," << i->getPassword() << endl;
            }
        }
      Write.close();
}
void Information :: SaveInfoRegisterToFileBankAccount(int Number){
      LoadFileRegisterCustomer();
      Info_Customer *Data_Customer;
      Data_Customer = HeadInfo_Customer;
      ofstream Write("BankAccount.dat",ios::app);
        if(Write){
            for(int i = 0; i < Number; i++){
                  if(i+1 == Number){
                        Write << Data_Customer->getName() << "," << "A" << "," << Data_Customer->getMoney() << "," << "B" << "," << "C" << endl;
                  }
                  Data_Customer = Data_Customer->link;
            }
        }
      Write.close();
}
void Information :: SaveInfoBankClerkToFile(){
      ofstream Write("BankClerk.dat");
        if(Write){
            for(Info_BankClerk *i = HeadInfo_BankClerk; i != NULL; i = i->link){
                Write << i->getName() << "," << i->getCitizenID() << "," << i->getBirthDate() << "," << i->getPhoneNumber() << "," << i->getClerkID() << "," << i->getPassword() << endl;
            }
        }
      Write.close();
}
void Information :: ShowRegistercustomer(){
      LoadFileRegisterCustomer();
      int count = 1;
      for(Info_Customer *i = HeadInfo_Customer; i != NULL; i = i->link){
            cout << count++ << "." << "\t" << i->getName() << endl;
            //cout << i->getName() << "," << i->getCitizenID() << "," << i->getBirthDate() << "," << i->getPhoneNumber() << "," << i->getTypeAccount() << "," << i->getMoney() << endl;
            //cout << i->getName() << "," << i->getCitizenID() << "," << i->getBirthDate() << "," << i->getPhoneNumber() << "," << i->getClerkID() << "," << i->getPassword() << endl;
            //cout << i->getName() << "," << i->getAccountNumber() << "," << i->getMoney() << "," << i->getUsername() << "," << i->getPassword() << endl;
      }
}
void Information :: ShowBankclerk(){
      for(Info_BankClerk *i = HeadInfo_BankClerk; i != NULL; i = i->link){
            cout << i->getName() << "," << i->getCitizenID() << "," << i->getBirthDate() << "," << i->getPhoneNumber() << "," << i->getClerkID() << "," << i->getPassword() << endl;
      }
}
void Information :: ShowBankAccount(){
      for(Info_BankAccount *i = HeadInfo_BankAccount; i != NULL; i = i->link){
            cout << i->getName() << "," << i->getAccountNumber() << "," << i->getMoney() << "," << i->getUsername() << "," << i->getPassword() << endl;
      }
}