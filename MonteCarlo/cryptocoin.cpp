#include "cryptocoin.h"

CryptoCoin::CryptoCoin() : _name("Unknown"), _abbreviation("UNKW"), _value_in_usd(0.0), _mod_rate(0.0) {
    actual_mod_rate = _mod_rate;
}

CryptoCoin::~CryptoCoin(){

}

QString CryptoCoin::name() {
    return this->_name;
}

void CryptoCoin::setName(const QString &name) {
    if (this->_name == name) {
        return;
    }
    else {
        this->_name = name;
        emit nameChanged();
    }
}

QString CryptoCoin::abbreviation(){
    return this->_abbreviation;
}

void CryptoCoin::setAbbreviation(const QString &abbv) {
    this->_abbreviation = abbv;
    emit abbreviationChanged();
}

double CryptoCoin::value_in_usd() {
    return this->_value_in_usd;
}

void CryptoCoin::setValue_in_usd(const double &value) {
    this->_value_in_usd = value;
    emit value_in_usdChanged();
}

double CryptoCoin::mod_rate() {
    return this->_mod_rate;
}

void CryptoCoin::setMod_rate(const double &rate) {
    this->_mod_rate = rate;
    this->actual_mod_rate = rate;
    emit mod_rateChanged();
}

double CryptoCoin::final_sum() {
    return this->_final_sum;
}

void CryptoCoin::setFinal_sum(const double &sum) {
    this->_final_sum = sum;
    emit final_sumChanged();
}

// Functia se va ocupa de simularea valorii monedei pe un interval de zile dat
/*
    Presupuneri:
    -> o moneda se poate aprecia sau deprecia
    -> rata de apreciere este fixa la 4%
    -> rata de depreciere este fixa la 6%
    -> probabilitatea de a se aprecia sau deprecia intr-o zi este data de mod_rate
    -> probabilitatea de apreciere este 50% initial
    -> dupa fiecare apreciere probabilitatea de apreciere scade cu 3%
    -> dupa fiecare depreciere probabilitatea de apreciere creste cu 5%
    -> daca o moneda nu se schimba intr-o zi, probabilitatea de modificare creste cu 1%, dupa ce se modifica, scade cu 3%, dar niciodata sub mod_rate
    -> vom genera aleator numere reale intre 1-100 si o sa comparam cu probabilitatile descrise mai sus
    -> scopul este ca la final sa vedem care dintre monedele noastre va fi cea mai profitabila pe o periada determinata de timp (pentru o investite)
*/
void CryptoCoin::simulate(int number_of_days) {
    // Generatorul de numere random (pseudo-random)
    default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());

    // Distributia de numere reale pentru care o sa folosim generatorul
    uniform_real_distribution<double> distribution(1.000,100.000);

    this->nr_of_coins = investment / this->_value_in_usd;
    // Rutina principala a simularii
    for (int i = 0; i < number_of_days; ++i) {
        // La inceputul simularii calculam numarul de monede echivalente cu investitia utilizatorului

        // Generam un numar aleator
        double nr = distribution(engine);

        // Verificam daca trebuie sa schimbam sau nu valoarea monedei pentru astazi
        if (nr <= actual_mod_rate) { // Atunci schimbam
            // Verificam daca trebuie sa apreciem sau sa depreciem valoarea monedei (generam alt numar)
            nr = distribution(engine);

            if (nr <= surge_prob) { // Atunci apreciem valoarea monedei
                setValue_in_usd(_value_in_usd + (_value_in_usd * 0.04));
                surge_prob -= 3;
                plumet_prob += 3;
            }
            else { // Altfel depreciem moneda
                setValue_in_usd(_value_in_usd - (_value_in_usd * 0.06));
                surge_prob += 5;
                plumet_prob -= 5;
            }

            // Scadem probabilitatea de modificare pentru ziua de maine, dar avem grija sa nu fie sub valoarea mod_rate initiale
            if (actual_mod_rate -= 3.0 >= _mod_rate) {
                actual_mod_rate -= 3.0;
            }
        }
        else { // Daca valoarea monedei nu se schimba astazi crestem probabilitatea de schimbare pentru maine
            actual_mod_rate += 1.0;
        }
    }

    // Afisam valoarea monedelor cumparate dupa simulare
    cout << "ROI -- " << this->_name.toUtf8().toStdString() << " = " << this->nr_of_coins * this->_value_in_usd << endl;
}

double CryptoCoin::investment = 1874.000;
