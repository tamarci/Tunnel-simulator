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
    Szimulacio sz;
    sz.init("test.txt");
    sz.run();
    return 0;
}
