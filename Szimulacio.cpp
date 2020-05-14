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

    //lamparendszer allitasa
    int kapcsolasiIdo = 10;

    while (ido.getIdo() != 100) {
        if (ido.getIdo() == 0) {
            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
        } else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All1)
            lampak.kovAllapot();
        else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All2) {
            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
        } else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All3)
            lampak.kovAllapot();
        else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All4) {
            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
        }

        //jarmuvek megallitasanak vizsgalasa a lampanal
        forgalom.lampanal(lampak.getAllapot());

        //Erzekelok novelese, csokkentese ha egy jarmu be, ki lép az alagutbol
        if (lampak.getAllapot() == All1 || lampak.getAllapot() == All2) {

            erzekelok.szamlaloNo(forgalom.fatlep(erzekelok.getPoz1()));
            erzekelok.szamlaloCsokken(forgalom.fatlep(erzekelok.getPoz2()));

        }
        else if (lampak.getAllapot() == All3 || lampak.getAllapot() == All4) {

            erzekelok.szamlaloNo(forgalom.fatlep(erzekelok.getPoz2()));
            erzekelok.szamlaloCsokken(forgalom.fatlep(erzekelok.getPoz1()));

        }


        //haladas,  gyorsitas
        forgalom.kovAllapot(ido, lampak.getAllapot());


        //ido leptetese
        ido.telik();
    }
}



