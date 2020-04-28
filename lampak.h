//
// Created by Marci on 2020. 04. 24..
//

#ifndef NAGYHAZI2_LAMPAK_H
#define NAGYHAZI2_LAMPAK_H

#include "enums.h"
//#include "memtrace.h"

class Lampa {
    Szin szin;
public:
    Lampa(Szin sz = piros) : szin(sz) {}

    Szin getSzin() const { return szin; }

    void szintVallt() {
        if (szin == piros)
            szin = zold;
        else
            szin = piros;
    }

    ~Lampa() {}
};

class Lamparendszer {
    Lampa l1, l2;
    Allapot allapot;
public:
    Lamparendszer() {}

    void init();

    void kovAllapot();

    Allapot getAllapot() const { return allapot; }

    ~Lamparendszer(){}


};

#endif //NAGYHAZI2_LAMPAK_H
