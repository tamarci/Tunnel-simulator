//
// Created by Marci on 2020. 04. 27..
//

#ifndef NAGYHAZI2_SZIMULACIO_H
#define NAGYHAZI2_SZIMULACIO_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "lampak.h"
#include "enums.h"
#include "jarmu.h"
#include "erzekelok.h"
#include "Idopont.h"
#include "Forgalom.h"
//#include "memtrace.h"



class Szimulacio {
    Lamparendszer lampak;
    Erzekelok erzekelok;
    Forgalom forgalom;
    Idopont ido;
    int palya;
public:
    Szimulacio(int hossz=100, int p1=20, int p2=80, int ido=0) :  erzekelok(p1, p2), ido(ido),palya(hossz) {}

    const Idopont& getIdo() const;

    int getPalya() const;

    void init(const char* Filenev);

    void run();

    ~Szimulacio() {}


};

#endif //NAGYHAZI2_SZIMULACIO_H
