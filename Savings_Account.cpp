#include <iostream>
#include "Savings_Account.h"

//constructor
Savings_Account::Savings_Account(std::string name,  double balance , double int_rate) 
    :Account{name, balance}, int_rate{int_rate} 
{        
}
  
//deposit method                                      
bool Savings_Account::deposit(double amount) {
    amount = amount + (amount*int_rate/100);
    return Account::deposit(amount);
}

//deposit method                                      
bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream & os) const {
    os.precision(2);
    os<<std::fixed;
   os << "[Saving Account: " << name <<", balance: "  << balance <<", int rate:  " << int_rate <<"%]";
}

//std::ostream & operator<<(std::ostream & os, const Savings_Account & account) {
//    os << "[Saving Account: " << account.name <<" : "  << account.balance <<" :  " 
//    << account.int_rate <<"%]";
//}