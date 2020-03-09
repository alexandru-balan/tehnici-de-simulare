#ifndef CRYPTOCOIN_H
#define CRYPTOCOIN_H

#include <iostream>
#include <random>
#include <chrono>
#include <QString>
#include <QObject>

using namespace std;
/*
 * Acest proiect isi propune sa creeze o aplicatie care, prin generarea numerelor in mod aleator,
 * sa prezica ce investitie este cea mai buna dintre Ethereum si Bitcoin. Anumiti parametri sunt luati in considerare
 * pentru realizarea acestei simulari si anume:
 * - valoarea investitiei si pretul unei cripto-monede => determina cate monede va detine utilizatorul pe parcursul simularii. In functie de
 *   fluctuatiile pretului aceste monede vor valora mai mult sau mai putin.
 * - volatilitatea monedei (in program _mod_rate) determina cat de des se va schimba pretul unei cripto-monede.
 * - alte probabilitati legate de crestere si cum se modifica volatilitatea se regasesc in fisierul cryptocoin.cpp alaturi de functia de simulare
 *
 * Aceasta aplicatie a fost realizata in limbajul C++ (partea de logica a aplicatiei) si QML (interfata aplicatiei) oferit de framework-up Qt
 * Proiectul a fost compilat si testat pe un sistem de operare GNU/Linux folosind Qt 5.14.1, GCC 9.2.1 si mediul de dezvoltare Qt Creator
 * Qt, GCC (prin mingw64) si Qt Creator sunt prezente si pentru sistemul de operare Windows.
 *
 *  Pentru a folosi aplicatia utilizatorul trebuie sa parcurga in ordine, urmatorii pasi:
 * 1. Modifica parametrii din interfata pentru a se potrivii nevoilor sale
 * 2. Apasa butonul pentru cumpararea cripto-monedelor (daca totul este in ordine, numarul de monede detinute se va modifica de la INFINITY la numarul actual calculat)
 * 3. Daca doreste sa modifice alti parametrii pana la pornirea simularii atunci trebuie sa cumpere iar monedele pentru a modifica numarul acestora
 * 4. Porneste simularea prin apasarea butonului din josul paginii.
*/
class CryptoCoin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString abbreviation READ abbreviation WRITE setAbbreviation NOTIFY abbreviationChanged)
    Q_PROPERTY(double value_in_usd READ value_in_usd WRITE setValue_in_usd NOTIFY value_in_usdChanged)
    Q_PROPERTY(double mod_rate READ mod_rate WRITE setMod_rate NOTIFY mod_rateChanged)
    Q_PROPERTY(double final_sum READ final_sum WRITE setFinal_sum NOTIFY final_sumChanged)
    Q_PROPERTY(double investment READ investment WRITE setInvestment NOTIFY investmentChanged)

private:
    QString _name;
    QString _abbreviation;
    double _value_in_usd;
    double _mod_rate;
    double _final_sum;

    double _investment;

    double surge_prob = 15;
    double plumet_prob = 75;
    double actual_mod_rate;

    double nr_of_coins = 0;

public:
    CryptoCoin(); //seteaza valori implicite atributelor criptomonedei
    ~CryptoCoin();

    /*
     * Urmatoarele functii sunt metode simple de tip get()/set()
     * Fiecare functie de tip set() emite un semnal pentru a lasa interfata QML sa stie
     * ca un anumit atribut a fost modificat.
    */
    QString name();
    void setName(const QString& name);

    QString abbreviation();
    void setAbbreviation(const QString& abbv);

    double value_in_usd();
    void setValue_in_usd(const double& value);

    double mod_rate();
    void setMod_rate(const double& rate);

    double final_sum();
    void setFinal_sum(const double& sum);

    double investment();
    void setInvestment(const double& inv);

    /*
     * Functiile sunt prefixate cu Q_INVOKABLE pentru a putea fi apelate de catre interfata scrisa in QML
    */
    Q_INVOKABLE void simulate(int number_of_days);
    Q_INVOKABLE double getCoins();
    Q_INVOKABLE void buyCoins();

signals:
    void nameChanged();
    void abbreviationChanged();
    void value_in_usdChanged();
    void mod_rateChanged();
    void final_sumChanged();
    void investmentChanged();
};

#endif // CRYPTOCOIN_H
