//
// Created by Marci on 2020. 04. 25..
//
#include "erzekelok.h"
//#include "memtrace.h"
void Erzekelok::vizsgal(Jarmu* j) {
    if (j->isIrany()) {
        if (poz2 <= j->getPoz())
            szamlalo--;
        else if (poz1 <= j->getPoz())
            szamlalo++;
    } else {
        if (poz1 >= j->getPoz())
            szamlalo--;
        else if (poz2 >= j->getPoz())
            szamlalo++;
    }
}