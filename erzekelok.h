//
// Created by Marci on 2020. 04. 25..
//

#ifndef NAGYHAZI2_ERZEKELOK_H
#define NAGYHAZI2_ERZEKELOK_H

#include <vector>
#include "jarmu.h"
//#include "memtrace.h"

class Erzekelok {
    int poz1, poz2;
    int szamlalo;
public:
    Erzekelok(int p1=20, int p2=80) : poz1(p1), poz2(p2), szamlalo(0) {}

    int getSzamlalo() const {
        return szamlalo;
    }

    void vizsgal(Jarmu* j);

    ~Erzekelok() {}
};

#endif //NAGYHAZI2_ERZEKELOK_H
