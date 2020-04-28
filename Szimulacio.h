//
// Created by Marci on 2020. 04. 27..
//

#ifndef NAGYHAZI2_SZIMULACIO_H
#define NAGYHAZI2_SZIMULACIO_H

#include "lampak.h"
#include "jarmu.h"
#include "erzekelok.h"
#include "Idopont.h"
//#include "memtrace.h"

#include <iostream>

class Szimulacio {
    Lamparendszer lampak;
    Erzekelok erzekelok;
    std::vector<Jarmu *> forgalom;
    Idopont ido;
    int palya;
public:
    Szimulacio(int hossz=100, int p1=20, int p2=80, int ido=0) :  erzekelok(p1, p2), ido(ido),palya(hossz) {}

    const Idopont& getIdo() const;

    int getPalya() const;

    void init();

    void run();

    ~Szimulacio() {}


};

#endif //NAGYHAZI2_SZIMULACIO_H
