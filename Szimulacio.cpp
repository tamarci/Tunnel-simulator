//
// Created by Marci on 2020. 04. 27..
//

#include "Szimulacio.h"
//#include "memtrace.h" // a memtrace a feltoltesnel hibat jelez,
// pedig meg nem is tortenik semmifele dinamikus memoria foglalas a programban, a rendes beadasig kideritem az okat
// de lehet, hogy a konyvtar hibas



void Szimulacio::init(const char *Filenev) {
    int id=0;
    char tipus;
    bool irany;
    Idopont erk, gyors;
    int spec;

    std::ifstream myfile(Filenev, std::ios_base::in);
    if (myfile.is_open()) {
        while (myfile >> tipus >> irany >> erk >> gyors >> spec) {
            switch (tipus) {
                case 'A':
                    forgalom.hozzad(new Auto(id,irany, erk, gyors, spec));
                    std::cout << "a";
                    break;
                case 'M':
                    forgalom.hozzad(new Motor(id,irany, erk, gyors, spec));
                    std::cout << "m";
                    break;
                case 'T':
                    forgalom.hozzad(new Truck(id,irany, erk, gyors, spec));
                    std::cout << "t";
                    break;
                default:
                    throw std::logic_error("Hibas bemeneti formatum");
                    break;
            }
            id++;
        }
        myfile.close();

    } else std::cout << "Unable to open file";

    std::cout << std::endl;
    forgalom.minden_kiir();

}

void Szimulacio::run() {

    //lamparendszer allitasa
    int kapcsolasiIdo = 10;

    while (ido.getIdo() != 120) {
        if (ido.getIdo() == 0) {

            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
            std::cout << ido << " Lamparendszer ALL1: l1=zold, l2=piros" << std::endl;

        } else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All1) {

            lampak.kovAllapot();
            std::cout << ido << " Lamparendszer ALL2: l1=piros, l2=piros" << std::endl;

        } else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All2) {

            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
            std::cout << ido << " Lamparendszer ALL3: l1=piros, l2=zold" << std::endl;

        } else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All3) {

            lampak.kovAllapot();
            std::cout << ido << " Lamparendszer ALL4: l1=piros, l2=piros" << std::endl;

        } else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All4) {

            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
            std::cout << ido << " Lamparendszer ALL1: l1=zold, l2=piros" << std::endl;
        }


        //jarmuvek megallitasanak vizsgalasa a lampanal
        forgalom.lampanal(lampak.getAllapot(), erzekelok.getPoz1(), erzekelok.getPoz2());

        //Erzekelok novelese, csokkentese ha egy jarmu be, ki lép az alagutbol
        if (lampak.getAllapot() == All1 || lampak.getAllapot() == All2) {

            erzekelok.szamlaloNo(forgalom.fatlep(erzekelok.getPoz1()));
            erzekelok.szamlaloCsokken(forgalom.fatlep(erzekelok.getPoz2()));

        } else if (lampak.getAllapot() == All3 || lampak.getAllapot() == All4) {

            erzekelok.szamlaloNo(forgalom.fatlep(erzekelok.getPoz2()));
            erzekelok.szamlaloCsokken(forgalom.fatlep(erzekelok.getPoz1()));

        }


        //haladas,  gyorsitas
        forgalom.kovAllapot(ido, lampak.getAllapot());


        //forgalom.minden_kiir();
        //ido leptetese
        ido.telik();


    }
}



