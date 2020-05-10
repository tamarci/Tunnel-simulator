//
// Created by Marci on 2020. 04. 27..
//

#include "Szimulacio.h"
//#include "memtrace.h" // a memtrace a feltoltesnel hibat jelez,
// pedig meg nem is tortenik semmifele dinamikus memoria foglalas a programban, a rendes beadasig kideritem az okat
// de lehet, hogy a konyvtar hibas


void Szimulacio::init(const char *Filenev) {
    char tipus;
    bool irany;
    Idopont erk, gyors;
    int spec;

    std::ifstream myfile(Filenev, std::ios_base::in);
    if (myfile.is_open()) {
        while (myfile >> tipus >> irany >> erk >> gyors >> spec) {
            switch (tipus) {
                case 'A':
                    forgalom.hozzad(new Auto(irany, erk, gyors, spec));
                    std::cout << "a";
                    break;
                case 'M':
                    forgalom.hozzad(new Motor(irany, erk, gyors, spec));
                    std::cout << "m";
                    break;
                case 'T':
                    forgalom.hozzad(new Truck(irany, erk, gyors, spec));
                    std::cout << "t";
                    break;
                default:
                    throw std::logic_error("Hibas bemeneti formatum");
                    break;
            }
        }
        myfile.close();

    } else std::cout << "Unable to open file";

    std::cout << std::endl;
    forgalom.minden_kiir();

    if (lampak.getAllapot() == Init)
        std::cout << "torold ezt a szar initet";

}

void Szimulacio::run() {
    //rendszer allitasa
    int kapcsolasiIdo = 10;
    while (ido.getIdo() != 100) {
        if (ido.getIdo() == 0){
            lampak.kovAllapot();
            kapcsolasiIdo=ido.getIdo();
        }
        else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All1)
            lampak.kovAllapot();
        else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All2){
            lampak.kovAllapot();
            kapcsolasiIdo=ido.getIdo();
        }
        else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All3)
            lampak.kovAllapot();
        else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All4) {
            lampak.kovAllapot();
            kapcsolasiIdo=ido.getIdo();
        }


        //Erzekelok


        //jarmuvek reagalasa

       forgalom.kovAllapot(ido,lampak.getAllapot());


        //masodik a nyero

        //ido leptetese
        ido.telik();
    }
}


const Idopont &Szimulacio::getIdo() const {
    return ido;
}

int Szimulacio::getPalya() const {
    return palya;
}

