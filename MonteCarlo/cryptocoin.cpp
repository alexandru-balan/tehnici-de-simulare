#include "cryptocoin.h"

CryptoCoin::CryptoCoin()
{
    this->name = "Unknown";
    this->abbreviation = "UNKW";
    this->mod_rate = 0.0;
    this->value_in_usd = 0.0;
}

CryptoCoin::CryptoCoin(string name, string abbreviation, double value) {
    this->name = name;
    this->abbreviation = abbreviation;
    this->value_in_usd = value;
    this->mod_rate = 0.0;
}

CryptoCoin::CryptoCoin(const CryptoCoin& CC) {
    this->name = CC.name;
    this->abbreviation = CC.abbreviation;
    this->value_in_usd = CC.value_in_usd;
    this->mod_rate = CC.mod_rate;
}

string CryptoCoin::getName(){
    return this->name;
}

string CryptoCoin::getAbbreviation(){
    return this->abbreviation;
}

double CryptoCoin::getValue(){
    return this->value_in_usd;
}

double CryptoCoin::getModRate(){
    return this->mod_rate;
}

void CryptoCoin::setModRate(double mod_rate){
   this->mod_rate = mod_rate;
}
