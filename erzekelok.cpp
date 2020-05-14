//
// Created by Marci on 2020. 04. 25..
//
#include "erzekelok.h"

//#include "memtrace.h"
void Erzekelok::szamlaloNo(int n) {
    szamlalo += n;
}

void Erzekelok::szamlaloCsokken(int n) {
    szamlalo -= n;
}

int Erzekelok::getPoz1() const {
    return poz1;
}

int Erzekelok::getPoz2() const {
    return poz2;
}

int Erzekelok::getSzamlalo() const {
    return szamlalo;
}