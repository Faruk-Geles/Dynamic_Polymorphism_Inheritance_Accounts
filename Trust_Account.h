#ifndef _TRUST_ACCOUNT_H_
#define  _TRUST_ACCOUNT_H_
#include <iostream>
#include "Savings_Account.h"

class Trust_Account: public Savings_Account {
    //friend std::ostream & operator<<(std::ostream & os, const Trust_Account & account);
private:
   static constexpr const char *name_def="Unnamed Trust Account";
   static constexpr double balance_def = 0.0;
   static constexpr double int_rate_def = 0.0;
   static constexpr int max_withdrawals = 3;
   static constexpr double bonus_amount = 50.0;
   static constexpr double bonus_threshold = 5000.0;
   static constexpr double max_withdrawal_percent=0.2;
protected:
    int num_withdrawals;
public: 
    Trust_Account(std::string name = name_def,  
                                    double balance=balance_def, 
                                    double int_rate=int_rate_def);
    virtual ~Trust_Account()=default;
    
    //deposit of more than $5000.00 or more will receive $50 bonus
    virtual bool deposit(double amount) override;
    
    //Only allowed maximum of 3 withdrawels each, can be up to a maximum of 20% of th account value
    virtual bool withdraw(double amount) override;
    
    virtual void print(std::ostream & os) const override;
};

#endif  //_TRUST_ACCOUNT_H_



