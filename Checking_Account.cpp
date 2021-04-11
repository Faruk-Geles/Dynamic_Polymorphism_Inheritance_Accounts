#include <iostream>
#include <string>
#include "Checking_Account.h"


Checking_Account::Checking_Account(std::string name, double balance)
    :Account{name, balance} 
{
}
   
//withdraw method 
bool Checking_Account::withdraw(double amount) {
    amount += withdraw_fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}


void Checking_Account::print(std::ostream & os) const {
    os.precision(2);
    os<<std::fixed;
    os <<"[Checking Account: " << name << ", balance: " <<balance 
    << ",  withdraw fee: " << withdraw_fee <<"$]";
}


//std::ostream & operator<<(std::ostream & os, const Checking_Account & account) {
//    os <<"[Checking Account: " << account.name << ": " <<account.balance 
//    << " withdraw fee: " << account.withdraw_fee <<"$]";
//    return os;
//}