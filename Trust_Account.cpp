#include <iostream>
#include "Trust_Account.h"


Trust_Account::Trust_Account(std::string name,  double balance, double int_rate)
    : Savings_Account(name, balance, int_rate), num_withdrawals{0}
{        
}

//deposit method
bool Trust_Account::deposit(double amount) {
    if(amount>=bonus_threshold) 
        amount +=bonus_amount;
    /*
   if(amount>0) {
       balance += amount;
       return true;
   } */
   return Savings_Account::deposit(amount);
}

//withdraw method
bool Trust_Account::withdraw(double amount) {
    if ((num_withdrawals>max_withdrawals) || (amount>max_withdrawal_percent*balance)) {
            return false;
    }
    ++num_withdrawals;
    return Savings_Account::withdraw(amount);
}

//std::ostream & operator<<(std::ostream & os, const Trust_Account & account) {
//    os << "[Trust account: " << account.name << ": " << account.balance << ": " 
//    << account.int_rate <<"%" << "number of withdrawel: " <<  account.num_withdrawals <<" ]";
//    return os;
//}

void Trust_Account::print(std::ostream & os) const {
    os.precision(2);
    os<<std::fixed;
    os << "[Trust account: " << name << ", balance: " << balance 
    << ", int_rate: "<< int_rate <<"%, " << " #withdrawel: " <<  num_withdrawals <<" ]";   
}