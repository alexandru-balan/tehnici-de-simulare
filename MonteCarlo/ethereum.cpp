#include "ethereum.h"

Ethereum::Ethereum():CryptoCoin()
{
    this->name = "Ethereum";
    this->abbreviation = "ETH";
}

Ethereum::Ethereum(double value, double mod_rate):CryptoCoin("Ethereum", "ETH", value){
    this->setModRate(mod_rate);
}

double Ethereum::getValue(){
    return this->value_in_usd;
}

double Ethereum::getModRate(){
    return this->mod_rate;
}

void Ethereum::setModRate(double mod_rate){
    this->mod_rate = mod_rate;
}
