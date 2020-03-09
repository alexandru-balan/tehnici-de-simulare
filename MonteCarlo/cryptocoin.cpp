#include "cryptocoin.h"

CryptoCoin::CryptoCoin() : _name("Unknown"), _abbreviation("UNKW"), _value_in_usd(0.0), _mod_rate(0.0) {
    actual_mod_rate = _mod_rate;
    _investment = 1847.00; // valoare default
    this->nr_of_coins = this->_investment / this->_value_in_usd;
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

double CryptoCoin::investment() {
    return _investment;
}

void CryptoCoin::setInvestment(const double& inv) {
    _investment = inv;
    emit investmentChanged();
}

/*
 * Returneaza numarul de cripto-monede cumparate de catre utilizator. Acest atribut nu poate fi setat de catre utilizator,
 * ci este modificat doar prin urmatorul procedeu:
 * -> schimbam valoarea investitiei si recumparam monedele
 * sau
 * -> schimbam valoare unei monede si recumparam monedele
*/
double CryptoCoin::getCoins() {
    return this->nr_of_coins;
}

/*
 * Functia calculeaza numarul de monede raportat la valoarea investitiei si preturile fiecarei cripto-monede
 * Prin aceasta metoda si cea de mai sus, ne asiguram ca numarul de monede nu se modifica pe parcursul simularii
 * impreuna cu pretul cripto-monedelor. Astfel putem oferii o suma finala corecta.
*/
void CryptoCoin::buyCoins() {
    this->nr_of_coins = this->_investment / this->_value_in_usd;
}

// Functia se va ocupa de simularea valorii monedei pe un interval de zile dat (setat in codul interfetei QML de unde este apelata functia de simulare)
/*
    Presupuneri:
    -> o moneda se poate aprecia sau deprecia
    -> rata de apreciere este fixa la 0.5%
    -> rata de depreciere este fixa la 0.5%
    -> probabilitatea de a se aprecia sau deprecia intr-o zi este data de mod_rate (numit si volatilitatea monedei)
    -> probabilitatea de apreciere este 15% initial
    -> dupa fiecare apreciere probabilitatea de apreciere scade cu 2%
    -> dupa fiecare depreciere probabilitatea de apreciere creste cu 2.03%
    -> daca o moneda nu se schimba intr-o zi, probabilitatea de modificare creste cu 1%, dupa ce se modifica, scade cu 3%, dar niciodata sub mod_rate
    -> vom genera aleator numere reale intre 1-100 si o sa comparam cu probabilitatile descrise mai sus
    -> scopul este ca la final sa vedem care dintre monedele noastre va fi cea mai profitabila pe o periada determinata de timp (pentru o investite)
*/
void CryptoCoin::simulate(int number_of_days) {
    // Generatorul de numere random (pseudo-random)
    default_random_engine engine(chrono::system_clock::now().time_since_epoch().count());

    // Distributia de numere reale pentru care o sa folosim generatorul
    uniform_real_distribution<double> distribution(1.000,100.000);

    // Rutina principala a simularii
    for (int i = 0; i < number_of_days; ++i) {

        // Generam un numar aleator
        double nr = distribution(engine);

        // Verificam daca trebuie sa schimbam sau nu valoarea monedei pentru astazi
        if (nr <= actual_mod_rate) { // Atunci schimbam
            // Verificam daca trebuie sa apreciem sau sa depreciem valoarea monedei (generam alt numar)
            nr = distribution(engine);

            if (nr <= surge_prob) { // Atunci apreciem valoarea monedei
                setValue_in_usd(_value_in_usd + (_value_in_usd * 0.005));
                surge_prob -= 2;
            }
            else { // Altfel depreciem moneda
                setValue_in_usd(_value_in_usd - (_value_in_usd * 0.005));
                surge_prob += 2.03;
            }

            // Scadem probabilitatea de modificare pentru ziua de maine, dar avem grija sa nu fie sub valoarea mod_rate initiala
            if (actual_mod_rate -= 3.0 >= _mod_rate) {
                actual_mod_rate -= 3.0;
            }
        }
        else { // Daca valoarea monedei nu se schimba astazi crestem probabilitatea de schimbare pentru maine
            actual_mod_rate += 1.0;
        }
    }

    // Afisam valoarea monedelor cumparate dupa simulare pentru depanare la consola
    cout << "ROI -- " << this->_name.toUtf8().toStdString() << " = " << this->nr_of_coins * this->_value_in_usd << endl;

    // Modificam valoarea atributului _final_sum pentru a fi afisat utilizatorului in interfata
    this->_final_sum = this->nr_of_coins * this->_value_in_usd;
}
