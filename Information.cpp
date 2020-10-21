#include "Information.h"
Information :: Info :: Info(Customer Data){
      customer = Data;
      link = NULL;
}
Information :: Info :: Info(BankAccount Data){
      bankaccount = Data;
      link = NULL;
}
Information :: Info :: Info(BankClerk Data){
      bankclerk = Data;
      link = NULL;
}
Information :: Information(){
      HeadInfo = NULL;
      TailInfo = NULL;
      CountAmount = 0;
}
Information :: ~Information(){
      Info *Value = HeadInfo;  
      for(int i=1;i<CountAmount;i++){
            Value = HeadInfo;
            HeadInfo = HeadInfo->link;
            delete Value;
            Value = NULL;
      }    
      HeadInfo = NULL;
      TailInfo = NULL;
}
void Information :: LoadFileRegisterCustomer(){
      string Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money,Line;
      ifstream Write;
      Customer Data;
      CountAmount = 0;
      HeadInfo = NULL;
      TailInfo = NULL;
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
              Data.SetInfoCustomer(Name,CitizenID,BirthDate,PhoneNumber,TypeAccount,Money);
              AddInfoRegisterCustomer(Data);
          }
          Write.close();
      }
}
void Information :: LoadFileBankAccount(){
      string Name,AccountNumber,Money,Username,Password,Line;
      ifstream Write;
      BankAccount Data;
      CountAmount = 0;
      HeadInfo = NULL;
      TailInfo = NULL;
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
              Data.SetInfoBankAccount(Name,AccountNumber,Money,Username,Password);
              AddInfoBankAccount(Data);
          }
          Write.close();
      }
}
void Information :: LoadFileBankClerk(){
      string Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password,Line;
      ifstream Write;
      BankClerk Data;
      CountAmount = 0;
      HeadInfo = NULL;
      TailInfo = NULL;
      Write.open("BankAccount.dat");
      if(Write.fail()){
        cout << "Can not Write File 'BankAccount.dat' " << endl;
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
              Data.SetInfoBankClerk(Name,CitizenID,BirthDate,PhoneNumber,ClerkID,Password);
              AddInfoBankClerk(Data);
          }
          Write.close();
      }
}
void Information :: AddInfoRegisterCustomer(Customer Data){
      Info *newCustomer = new Info(Data);
            if(HeadInfo == NULL){
                HeadInfo = newCustomer;
                TailInfo = newCustomer;
            }
            else{
                TailInfo->link = newCustomer;
                TailInfo = newCustomer;
            }
            CountAmount++;
}
void Information :: AddInfoBankAccount(BankAccount Data){
      Info *newBankAccount = new Info(Data);
            if(HeadInfo == NULL){
                HeadInfo = newBankAccount;
                TailInfo = newBankAccount;
            }
            else{
                TailInfo->link = newBankAccount;
                TailInfo = newBankAccount;
            }
            CountAmount++;
}
void Information :: AddInfoBankClerk(BankClerk Data){
      Info *newBankClerk = new Info(Data);
            if(HeadInfo == NULL){
                HeadInfo = newBankClerk;
                TailInfo = newBankClerk;
            }
            else{
                TailInfo->link = newBankClerk;
                TailInfo = newBankClerk;
            }
            CountAmount++;
}
void Information :: RemoveInfoRegisterCustomer(int Number){
      Info *temp,*ptemp;
      temp = HeadInfo;
      for(int i = 1; i < CountAmount; i++){
            if(i == Number){
                  if(i==1){
                        HeadInfo = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  CountAmount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: RemoveInfoBankAccount(string AccountNumber){
      Info *temp,*ptemp;
      temp = HeadInfo;
      for(Info *i = HeadInfo; i != NULL; i = i->link){
            if(i->bankaccount.getAccountNumber() == AccountNumber){
                  if(i==HeadInfo){
                        HeadInfo = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  CountAmount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: RemoveInfoBankClerk(int Number){
      Info *temp,*ptemp;
      temp = HeadInfo;
      for(int i = 1; i < CountAmount; i++){
            if(i == Number){
                  if(i==1){
                        HeadInfo = temp->link;
                  }
                  else{
                        ptemp->link = temp->link;
                  }
                  CountAmount--;
                  delete temp;
            }
            ptemp = temp;
	      temp = temp->link; 
      }
}
void Information :: SaveInfoRegisterCustomerToFile(){
      ofstream Write("RegisterAccountCustomer.dat");
        if(Write){
            for(Info *i = HeadInfo; i != NULL; i = i->link){
                Write << i->customer.getName() << "," << i->customer.getCitizenID() << "," << i->customer.getBirthDate() << "," << i->customer.getPhoneNumber() << "," << i->customer.getTypeAccount() << "," << i->customer.getMoney() << endl;
            }
        }
      Write.close();
}
void Information :: SaveInfoCustomerToFile(){
      ofstream Write("BankAccount.dat");
        if(Write){
            for(Info *i = HeadInfo; i != NULL; i = i->link){
                Write << i->bankaccount.getName() << "," << i->bankaccount.getAccountNumber() << "," << i->bankaccount.getMoney() << "," << i->bankaccount.getUsername() << "," << i->bankaccount.getPassword() << endl;
            }
        }
      Write.close();
}
void Information :: SaveInfoBankClerkToFile(){
      ofstream Write("BankClerk.dat");
        if(Write){
            for(Info *i = HeadInfo; i != NULL; i = i->link){
                Write << i->bankclerk.getName() << "," << i->bankclerk.getCitizenID() << "," << i->bankclerk.getBirthDate() << "," << i->bankclerk.getPhoneNumber() << "," << i->bankclerk.getClerkID() << "," << i->bankclerk.getPassword() << endl;
            }
        }
      Write.close();
}
void Information :: Show(){
      for(Info *i = HeadInfo; i != NULL; i = i->link){
            cout << i->customer.getName() << "," << i->customer.getCitizenID() << "," << i->customer.getBirthDate() << "," << i->customer.getPhoneNumber() << "," << i->customer.getTypeAccount() << "," << i->customer.getMoney() << endl;
            //cout << i->bankclerk.getName() << "," << i->bankclerk.getCitizenID() << "," << i->bankclerk.getBirthDate() << "," << i->bankclerk.getPhoneNumber() << "," << i->bankclerk.getClerkID() << "," << i->bankclerk.getPassword() << endl;
            //cout << i->bankaccount.getName() << "," << i->bankaccount.getAccountNumber() << "," << i->bankaccount.getMoney() << "," << i->bankaccount.getUsername() << "," << i->bankaccount.getPassword() << endl;
      }
}