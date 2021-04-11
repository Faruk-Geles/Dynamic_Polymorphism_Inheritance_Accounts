#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_aCCOUNT_H_
#include <string>
#include "Account.h"

class Checking_Account : public Account {
    //friend std::ostream & operator<<(std::ostream & os, const Checking_Account & account);
private:
    static constexpr const char *name_def="Unnamed Checking Account " ;
    static constexpr  double balance_def = 0.0;
    static constexpr double withdraw_fee = 1.5;
//protected:
    
public:
    Checking_Account(std::string name=name_def, double balance=balance_def);
    virtual ~Checking_Account() = default; //{};
    virtual bool deposit(double amount)  override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream & os) const override;
};

#endif //_CHECKING_aCCOUNT_H_