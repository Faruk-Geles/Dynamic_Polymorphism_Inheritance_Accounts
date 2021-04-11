#include "Account.h"

//Constructor
Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if(amount>0) {
        balance += amount;
        return true;
    }
    return false;
}


bool Account::withdraw(double amount ) {
    if(balance-amount>=0) {
        balance -= amount;
        return true;
    } else {
        std::cout <<"Insufficient funds" <<std::endl;
    }
    return false;
}

void Account::print(std::ostream & os) const {
    os.precision(2);
    os<<std::fixed;
    os <<"[Account : " << name << ": "<<balance << "]";
}