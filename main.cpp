#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;
int main()
{
    //Account joe;     //ERROR ABSTRACT CLASS
    
    std::cout <<"\n========================================="<<std::endl;
    Checking_Account c{"Hans",200};
    c.deposit(1000);
    std::cout <<c <<std::endl;
    
    Savings_Account s1{"Hans",5000,2.6};
    std::cout <<s1 <<std::endl;
    s1.deposit(10000);
    std::cout <<s1 <<std::endl;
    s1.withdraw(10000);
    std::cout <<s1 <<std::endl;
    std::cout <<"\n========================================="<<std::endl;

    
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
    std::cout <<"\n========================================="<<std::endl;
    //Examples with smart pointers(unique pointers)
    std::unique_ptr<Account> t11{new Trust_Account{"Olaf",100,0.1}};
    std::cout << *t11 << std::endl;
    //std::shared_ptr<Account> t11new{t11};   //ERROR
    
    
    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("James",1000);
    std::cout << *a1 << std::endl;
    a1 -> deposit(5000);
    std::cout << *a1 << std::endl;
    
    std::vector<std::unique_ptr<Account>> accounts_new;
    accounts_new.push_back(make_unique<Checking_Account>("James Olli", 1000));
    accounts_new.push_back(make_unique<Savings_Account>("Billy", 4000,5.2));
    accounts_new.push_back(make_unique<Trust_Account>("Bobby", 5000, 4.5));
    for (const auto & acc : accounts_new) {
        std::cout<<*acc << std::endl;
    }
    
    std::cout <<"\n========================================="<<std::endl;
    //Examples with smart pointers(shared pointers)
    std::shared_ptr<Account> t22{new Trust_Account{"Olaf2", 200, 0.2}};
    std::cout << *t22 << std::endl;
    std::cout<<"Use count: "<< t22.use_count() << std::endl;    //1
    std::shared_ptr<Account> t22new{t22};
    std::cout << *t22new<<std::endl;
    std::cout<<"Use count: "<< t22.use_count() << std::endl;              //2
    std::cout<<"Use count: "<< t22new.use_count() << std::endl;     //2
    
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry",3000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe",5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);
    
    std::vector<std::shared_ptr<Account>> accounts_new2;
    accounts_new2.push_back(acc1);
    accounts_new2.push_back(acc2);
    accounts_new2.push_back(acc3);
    
    for(const auto & acc:accounts_new2) {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() <<std::endl;
    }
    
    

    
    
    
	printf("hello world\n");
	return 0;
}