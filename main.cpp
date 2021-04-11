#include <stdio.h>
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;
int main()
{
    //Account joe;     //ERROR ABSTRACT CLASS
    
    Checking_Account c{"Hans",200};
    c.deposit(1000);
    std::cout <<c <<std::endl;
    
    Savings_Account s1{"Hans",5000,2.6};
    std::cout <<s1 <<std::endl;
    s1.deposit(10000);
    std::cout <<s1 <<std::endl;
    s1.withdraw(10000);
    std::cout <<s1 <<std::endl;

    
    Account * ptr = new Trust_Account("Leo",10000,2.6);
    cout << *ptr << endl;
    delete ptr;
    
    Account *p1 = new Trust_Account{};
    Account *p2 = new Savings_Account{};
    Account *p3 = new Checking_Account{"Franz"};
    Account *p4 = new Trust_Account{"Joe",2000};
    
    vector<Account *> accounts={p1,p2,p3,p4};
    
    display(accounts);
    
    deposit(accounts,1000);
    withdraw(accounts, 2000);
    
    display(accounts);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    /*
    std::cout.precision(2);
    std::cout <<fixed;
    
    Trust_Account a1{"Peter",2000};
    a1.deposit(1000);
    std::cout <<a1 <<std::endl;
    
    Checking_Account c1{"Hans",200};
    c1.deposit(1000);
    std::cout <<c1 <<std::endl;
    
    Savings_Account s1{"Hans",200};
    s1.deposit(1000);
    std::cout <<s1 <<std::endl;
    
    Account *p1 = new Savings_Account();
    std::cout << *p1 <<std::endl;
    delete p1;
    
    cout <<"\n================================"<<endl;
    
    //Account *p1 = new Account();
    //Account *p2 = new Savings_Account();
    //Account *p3 = new Checking_Account("Larry");
    //Account *p4 = new Trust_Account("Moe",2000);
    
    //Accounts
    //vector<Account *> accounts={p2,p3,p4};
    //vector <Account*> accounts;
    //accounts.push_back( &Account{})
    //accounts.push_back(&Account{"Larry"});
    //accounts.push_back(&Account{"Moe",2000});
    //accounts.push_back(&Account{"Curly",5000});
    //display(accounts);
    
    //delete p1;
    //delete p2;
    //delete p3;
    
    
    */
    
    
    
    
	printf("hello world\n");
	return 0;
}
