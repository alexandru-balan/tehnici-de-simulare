#ifndef BITCOIN_H
#define BITCOIN_H

#include "cryptocoin.h"

using namespace std;

class Bitcoin : public CryptoCoin
{
public:
    Bitcoin();
    Bitcoin(double value, double mod_rate);
    double getValue() override;
    double getModRate() override;
    void setModRate(double mod_rate) override;
};

#endif // BITCOIN_H
