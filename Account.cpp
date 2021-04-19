#include "Account.h"

//Constructor
Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} { 
        if(balance<0.0)
            throw IllegalBalanceException{};
}
//Deposit method
bool Account::deposit(double amount) {
    if (amount<0)
        return false;
    balance += amount;
    return true;
}
//withdraw method
bool Account::withdraw(double amount) {
    if(balance-amount>0) {
        balance -= amount;
        return true;
    }  else {
        return false;
    } 
}

//print method
void Account::print(std::ostream & os) const {
    os.precision(2);
    os<<std::fixed;
    os<<"[Account : " << name << ": " << balance <<"]";
}