#ifndef BITCOIN_H
#define BITCOIN_H

#include "cryptocoin.h"

using namespace std;

class Bitcoin : public CryptoCoin
{
    Q_OBJECT

public:
    Bitcoin();
};

#endif // BITCOIN_H
