//
// Created by Marci on 2020. 04. 27..
//

#include "Szimulacio.h"
//#include "memtrace.h" // a memtrace a feltoltesnel hibat jelez,
// pedig meg nem is tortenik semmifele dinamikus memoria foglalas a programban, a rendes beadasig kideritem az okat
// de lehet, hogy a konyvtar hibas


void Szimulacio::init() {
    std::cout << "Ez a fuggveny fogja inicializálni a rendszert, es bolvasnni az adatokat" << std::endl;
}

void Szimulacio::run() {
    std::cout
            << "Ebben a függvényben fognak a futni a fo algoritmusok, osszehangolja a mukodest, a mainbe csak ezt kell majd hivni"
            << std::endl;
}


const Idopont &Szimulacio::getIdo() const {
    return ido;
}

int Szimulacio::getPalya() const {
    return palya;
}
