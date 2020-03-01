#ifndef CRYPTOCOIN_H
#define CRYPTOCOIN_H

#include <iostream>
#include <random>
#include <chrono>
#include <QString>
#include <QObject>

using namespace std;
/*
    CryptoCoint is an abstract class that serves as an interface for actual coins.
This class will implement basic characteristics that are intrinsec to evey coin.
*/
class CryptoCoin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString abbreviation READ abbreviation WRITE setAbbreviation NOTIFY abbreviationChanged)
    Q_PROPERTY(double value_in_usd READ value_in_usd WRITE setValue_in_usd NOTIFY value_in_usdChanged)
    Q_PROPERTY(double mod_rate READ mod_rate WRITE setMod_rate NOTIFY mod_rateChanged)
    Q_PROPERTY(double final_sum READ final_sum WRITE setFinal_sum NOTIFY final_sumChanged)

private:
    QString _name;
    QString _abbreviation;
    double _value_in_usd;
    double _mod_rate;
    double _final_sum;

    static double investment;

    double surge_prob = 50;
    double plumet_prob = 50;
    double actual_mod_rate;
    double nr_of_coins = 0;

public:
    CryptoCoin();
    ~CryptoCoin();

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

    Q_INVOKABLE void simulate(int number_of_days);

signals:
    void nameChanged();
    void abbreviationChanged();
    void value_in_usdChanged();
    void mod_rateChanged();
    void final_sumChanged();
};

#endif // CRYPTOCOIN_H
