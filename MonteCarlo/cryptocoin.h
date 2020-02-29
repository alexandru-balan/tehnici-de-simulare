#ifndef CRYPTOCOIN_H
#define CRYPTOCOIN_H

#include <iostream>
#include <cstring>

using namespace std;
/*
    CryptoCoint is an abstract class that serves as an interface for actual coins.
This class will implement basic characteristics that are intrinsec to evey coin.
*/
class CryptoCoin
{
protected:
    string name;
    string abbreviation;
    double value_in_usd;
    double mod_rate;
public:
    CryptoCoin();
    CryptoCoin(string name, string abbreviation, double value);
    CryptoCoin(const CryptoCoin& CC);
    string getName();
    string getAbbreviation();
    virtual double getValue() = 0;
    virtual double getModRate();
    virtual void setModRate(double mod_rate);
};

#endif // CRYPTOCOIN_H
