#include "bitcoin.h"

Bitcoin::Bitcoin():CryptoCoin()
{
    this->name = "Bitcoin";
    this->abbreviation = "BTC";
}

Bitcoin::Bitcoin(double value, double mod_rate):CryptoCoin("Bitcoin", "BTC", value) {
    this->setModRate(mod_rate);
}

double Bitcoin::getValue() {
    return this->value_in_usd;
}

double Bitcoin::getModRate() {
    return this->mod_rate;
}

void Bitcoin::setModRate(double mod_rate){
    this->mod_rate = mod_rate;
}
