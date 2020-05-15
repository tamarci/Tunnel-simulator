//
// Created by Marci on 2020. 04. 27..
//

#include "Szimulacio.h"
//#include "memtrace.h" // a memtrace a feltoltesnel hibat jelez,
// pedig meg nem is tortenik semmifele dinamikus memoria foglalas a programban, a rendes beadasig kideritem az okat
// de lehet, hogy a konyvtar hibas



// beolvasas a fajlbol, adatszerkezet letrehozasa
void Szimulacio::init(const char *Filenev) {
    int id=0;
    char tipus;
    bool irany;
    Idopont erk, gyors;
    int spec;



    std::ifstream myfile(Filenev, std::ios_base::in);

    std::string line;
    //helyes formátumu sor regex kifejezese
    std::regex regex("([ATM] [0-1] (([0-1][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9] ){2}[0-9]+)");
    std::smatch match;

    if (myfile.is_open()) {

        while (std::getline(myfile,line)) { //utolso sorig olvas
        if(regex_match(line, match, regex)){    //helyes formatumu?
            try{
                std::stringstream (line) >> tipus >> irany >> erk >> gyors >> spec;
            switch (tipus) { //letrehozza a megfelelo jarmu tipus
                case 'A':
                    forgalom.hozzad(new Auto(id,irany, erk, gyors, spec));
                    break;
                case 'M':
                    forgalom.hozzad(new Motor(id,irany, erk, gyors, spec));
                    break;
                case 'T':
                    forgalom.hozzad(new Truck(id,irany, erk, gyors, spec));
                    break;
                default:
                    throw std::runtime_error("Hibas bemeneti formatum");
            }
            id++;
            }
            catch(const std::exception& e){
                std::cout<< e.what() <<std::endl;

            }
        }
        }
        myfile.close();

    } else std::cout << "Unable to open file";

    std::cout << std::endl;
    forgalom.minden_kiir();

}


//ebben a fuggvenyben fut maga a szimulacio
//vezerli a lampa rendszert az erzekelok alapjan es utemezi az autok haladasat

void Szimulacio::run() {

    //ennyi ideig lesz zold a lampa
    int kapcsolasiIdo = 10;

    while (forgalom.getSize() != 0) {  //Addig fut a szimulacio amig az utolso auto el nem hagyta a palyat
        if (ido.getIdo() == 0) {  //allapotok leptetesi feltetelei

            lampak.kovAllapot();
            kapcsolasiIdo = ido.getIdo();
            std::cout << ido << " Lamparendszer ALL1: l1=zold, l2=piros" << std::endl;

        } else if (ido.getIdo() - kapcsolasiIdo == 10 && lampak.getAllapot() == All1) {
            //akkor vallt pirosra ha lejart a kapcsolasi ido
            lampak.kovAllapot();
            std::cout << ido << " Lamparendszer ALL2: l1=piros, l2=piros" << std::endl;

        } else if (erzekelok.getSzamlalo() == 0 && lampak.getAllapot() == All2) {
            //akkor lehet ujra zold ha mar ures az alagut, nincs szembe forgalom
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


        //jarmuvek megallasanak vizsgalasa a lampanal
        forgalom.lampanal(lampak.getAllapot(), erzekelok.getPoz1(), erzekelok.getPoz2());

        //Erzekelok novelese, csokkentese ha egy jarmu be, ki lep az alagutbol
        if (lampak.getAllapot() == All1 || lampak.getAllapot() == All2) {

            erzekelok.szamlaloNo(forgalom.fatlep(erzekelok.getPoz1()));
            erzekelok.szamlaloCsokken(forgalom.fatlep(erzekelok.getPoz2()));

        } else if (lampak.getAllapot() == All3 || lampak.getAllapot() == All4) {
        //a 0 es 1 haladasi iranyokra kulon kell vizsgalni
            erzekelok.szamlaloNo(forgalom.fatlep(erzekelok.getPoz2()));
            erzekelok.szamlaloCsokken(forgalom.fatlep(erzekelok.getPoz1()));

        }


        //haladas,  gyorsitas,torles
        forgalom.kovAllapot(ido, lampak.getAllapot());

        //ido leptetese
        ido.telik();


    }
}



