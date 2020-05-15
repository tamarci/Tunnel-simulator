//
// Created by Marci on 2020. 05. 03..
//

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "lampak.h"
#include "jarmu.h"
#include "erzekelok.h"
#include "Idopont.h"
#include "Forgalom.h"
#include "Szimulacio.h"

int main(){
    //letrehoz egy szimulaciot a fajl alapjan es futtatja azt
    Szimulacio sz;

    std::cout<<"KIOLVASOTT SZIMULACIOS ADATOK:"<<std::endl;
    sz.init("test.txt");

    std::cout<<"SZIMULACIO FUTASA:"<<std::endl;
    sz.run();

    return 0;
}
