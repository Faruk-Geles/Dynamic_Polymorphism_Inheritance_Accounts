#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include <string>
#include <iostream>
#include "Account.h"

class Savings_Account: public Account {
    //friend std::ostream & operator<<(std::ostream & os, const Savings_Account & account); 
private:
   static constexpr const char *name_def="Unnamed Savings Account ";
   static constexpr double balance_def=0.0;
   static constexpr double int_rate_def =0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name= name_def,  
                                        double balance = balance_def, 
                                        double int_rate=int_rate_def);
    virtual ~Savings_Account() = default;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream & os) const override;
 
};

#endif //_SAVINGS_ACCOUNT_H_