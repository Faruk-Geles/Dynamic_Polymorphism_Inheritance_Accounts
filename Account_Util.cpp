#include <iostream>
#include "Account_Util.h"

//Display Account objects in a vector of Account object pointers
void display(const std::vector<Account *> & accounts) {
    std::cout <<"\n=====Accounts=========================="<<std::endl;
    for( const auto acc_ptr : accounts ) {
        std::cout << *acc_ptr <<std::endl;
    }
}

//Deposits amount to each Account object in the vector
void deposit(std::vector<Account *> & accounts, double amount) {
    std::cout <<"\n=====Depositing the Accounts=============="<<std::endl;
    for(auto acc_ptr : accounts) {
        if(acc_ptr->deposit(amount)) 
            std::cout <<"Deposited " << amount <<" to " << *acc_ptr <<std::endl;
        else
            std::cout <<"Failed Deposit of " << amount <<" to " << *acc_ptr <<std::endl;
    }
}

//Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account *> & accounts, double amount) {
    std::cout <<"\n=====Withdraw Accounts=================="<<std::endl;
    for(auto acc_ptr : accounts) {
        if(acc_ptr->withdraw(amount))
            std::cout <<"Withdraw " << amount <<" from " << *acc_ptr << std::endl;
        else
            std::cout <<"Failed withdrawal of " << amount <<" from " << *acc_ptr << std::endl;
    }
}