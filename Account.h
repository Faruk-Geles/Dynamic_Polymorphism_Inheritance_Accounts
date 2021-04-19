#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>
#include "I_Printable.h"
#include "IllegalBalanceException.h"

//Abstract class
class Account: public I_Printable, public IllegalBalanceException {
private:
    static constexpr const char *name_def="Unnamed Account ";
    static constexpr  double balance_def = 0.0;  
protected:
    std::string name;
   double balance; 
public:
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    Account(std::string name=name_def, double balance=balance_def);
    virtual void print (std::ostream & os) const override;
    
    virtual ~Account() = default;                   //Virtual destructor
};

#endif //_ACCOUNT_H_