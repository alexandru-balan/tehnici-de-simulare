#ifndef ETHEREUM_H
#define ETHEREUM_H

#include "cryptocoin.h"

using namespace std;

class Ethereum : public CryptoCoin
{
public:
    Ethereum();
    Ethereum(double value, double mod_rate);
    double getValue() override;
    double getModRate() override;
    void setModRate(double mod_rate) override;
};

#endif // ETHEREUM_H
