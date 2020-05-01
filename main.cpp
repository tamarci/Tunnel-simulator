#include "Idopont.h"
#include <iostream>
#include "lampak.h"
#include "erzekelok.h"
#include "jarmu.h"
#include "Szimulacio.h"

//#include "memtrace.h"  // a memtrace a feltoltesnel hibat jelez,
// pedig meg nem is tortenik semmifele dinamikus memoria foglalas a programban, a rendes beadasig kideritem az okat
// de lehet, hogy a konyvtar hibas
#include "gtest_lite.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    //osztalyok es tagfuggvenyeik tesztelese gtest_lite hasznalataval
    GTINIT(std::cin);
//Szimulacio
    //konstruktor
    TEST(SzimKonst, construct)
        {
            Szimulacio sz;;
            EXPECT_EQ((int)100, sz.getPalya()) << "Rossz a palya hossza" << endl;
            EXPECT_EQ((Idopont)0, sz.getIdo()) << "Rossz az ido inicializalsa" << endl;
            //a tobbi elemet kozvetlenul teszteljuk
        }
    ENDM
    //init:
    //Ez a fuggveny fogja inicializálni a rendszert, es az  adatok beolvasasert lesz felelos
    // run:
    // Ebben a fuggvenyben fognak a futni a fo algoritmusok, osszehangolja a mukodest, a mainbe csak ezt kell majd hivni
    // a szimulacio futtatasahoz

//Jarmuvek
    //konstruktor
    TEST(AutoKonst, construct)
        {
            Auto a(0,120,1010,1);
            EXPECT_EQ((int)100, a.getPoz()) << "Rossz a kezdeti poz" << endl;
            EXPECT_EQ((int)4, a.getSpeed()) << "Rossz az sebesseg" << endl;
            EXPECT_EQ((bool)false, a.isIrany()) << "Rossz a irany" << endl;
            EXPECT_EQ((Idopont)120, a.getErkezes()) << "Rossz az ido inicializalsa" << endl;
            EXPECT_EQ((Idopont)1010, a.getGyorsitas()) << "Rossz az ido inicializalsa" << endl;
            EXPECT_EQ((int)1, a.getUtasokszama()) << "Rossz az ido inicializalsa" << endl;

            Auto b;
            EXPECT_EQ((int)0, b.getPoz()) << "Rossz a kezdeti poz" << endl;
            EXPECT_EQ((int)2, b.getUtasokszama()) << "Rossz az ido inicializalsa" << endl;
        }
    ENDM

    TEST(MotorKonst, construct)
        {
            Motor a(1,20,110,10);
            EXPECT_EQ((int)0, a.getPoz()) << "Rossz a kezdeti poz" << endl;
            EXPECT_EQ((int)4, a.getSpeed()) << "Rossz az sebesseg" << endl;
            EXPECT_EQ((bool)true, a.isIrany()) << "Rossz a irany" << endl;
            EXPECT_EQ((Idopont)20, a.getErkezes()) << "Rossz az ido inicializalsa" << endl;
            EXPECT_EQ((Idopont)110, a.getGyorsitas()) << "Rossz az ido inicializalsa" << endl;
            EXPECT_EQ((int)10, a.getMaxSpeed()) << "Rossz az ido inicializalsa" << endl;

            Motor b;
            EXPECT_EQ((int)0, b.getPoz()) << "Rossz a kezdeti poz" << endl;
            EXPECT_EQ((int)10, b.getMaxSpeed()) << "Rossz az ido inicializalsa" << endl;
        }
    ENDM

    TEST(TruckKonst, construct)
        {
            Truck a(0,2101,2110,120);
            EXPECT_EQ((int)100, a.getPoz()) << "Rossz a kezdeti poz" << endl;
            EXPECT_EQ((int)4, a.getSpeed()) << "Rossz az sebesseg" << endl;
            EXPECT_EQ((bool)false, a.isIrany()) << "Rossz a irany" << endl;
            EXPECT_EQ((Idopont)2101, a.getErkezes()) << "Rossz az ido inicializalsa" << endl;
            EXPECT_EQ((Idopont)2110, a.getGyorsitas()) << "Rossz az ido inicializalsa" << endl;
            EXPECT_EQ((int)120, a.getTomeg()) << "Rossz az ido inicializalsa" << endl;

            Truck b;
            EXPECT_EQ((int)0, b.getPoz()) << "Rossz a kezdeti poz" << endl;
            EXPECT_EQ((int)100, b.getTomeg()) << "Rossz az ido inicializalsa" << endl;
        }
    ENDM

    //halad teszt
    TEST(Auto, halad)
        {
            //mindket iranyba
            Auto a(0,120,1010,1);
            a.halad();
            EXPECT_EQ((int)96, a.getPoz()) << "Rossz haladasi ertek" << endl;

            //masik irany
            Auto b(1,120,1010,1);
            b.halad();
            EXPECT_EQ((int)4, b.getPoz()) << "Rossz haladasi ertek" << endl;

        }
    ENDM

    //changeSpeed() fv
    TEST(Auto, changeSpeed)
        {

            Auto a(1,120,1010,1);
            a.changeSpeed();
            EXPECT_EQ((int)5, a.getSpeed()) << "Rossz haladasi ertek" << endl;

        }
    ENDM

    TEST(Motor, changeSpeed)
        {

            Motor a(1,120,1010,7);
            a.changeSpeed();
            EXPECT_EQ((int)7, a.getSpeed()) << "Rossz haladasi ertek" << endl;

        }
    ENDM

    TEST(Truck, changeSpeed)
        {

            Truck a(1,120,1010,100);
            a.changeSpeed();
            EXPECT_EQ((int)6, a.getSpeed()) << "Rossz haladasi ertek" << endl;

        }
    ENDM


//lampa allapotanak vizsgalata
    TEST(Jarmu, checkLampa)
        {
            //összes allapot tesztelese
            Auto a(1,120,1010,100);
            Allapot allapot = All1 ;
            EXPECT_EQ((bool)true, a.checkLampa(allapot)) << "Rossz erzekelo ertek" << endl;
            allapot=All2;
            EXPECT_EQ((bool)false, a.checkLampa(allapot)) << "Rossz erzekelo ertek" << endl;
            allapot=All3;
            EXPECT_EQ((bool)false, a.checkLampa(allapot)) << "Rossz erzekelo ertek" << endl;
            allapot=All4;
            EXPECT_EQ((bool)false, a.checkLampa(allapot)) << "Rossz erzekelo ertek" << endl;

            //masik iranyba is
            Auto b(0,120,1010,100);
            Allapot all = All1 ;
            EXPECT_EQ((bool)false, b.checkLampa(all)) << "Rossz erzekelo ertek" << endl;
            all=All2;
            EXPECT_EQ((bool)false, b.checkLampa(all)) << "Rossz erzekelo ertek" << endl;
            all=All3;
            EXPECT_EQ((bool)true, b.checkLampa(all)) << "Rossz erzekelo ertek" << endl;
            all=All4;
            EXPECT_EQ((bool)false, b.checkLampa(all)) << "Rossz erzekelo ertek" << endl;
        }
    ENDM

    //Idopont tesztek
    TEST(Idopont, classtest)
        {

            Idopont i(1201);
            Idopont k;

            EXPECT_EQ((Idopont)0, k) << "Rossz idopont ertek" << endl;
            k=i;
            EXPECT_EQ((Idopont)1201, k) << "Rossz idopont ertek" << endl;
            EXPECT_EQ((bool)true, k==i) << "Rossz idopont ertek" << endl;
            EXPECT_EQ((bool)true, k>=i) << "Rossz idopont ertek" << endl;
            k.telik();
            EXPECT_EQ((Idopont)1202, k) << "Rossz idopont ertek" << endl;
        }
    ENDM

    //Lampatesztek
    TEST(Lampa, classtest)
        {

            Lampa l;
            EXPECT_EQ((Szin)piros, l.getSzin()) << "Rossz szin" << endl;
            l.szintVallt();
            EXPECT_EQ((Szin)zold, l.getSzin()) << "Rossz szin" << endl;
            l.szintVallt();
            EXPECT_EQ((Szin)piros, l.getSzin()) << "Rossz szin" << endl;
        }
    ENDM

    //Lamparendszer tesztek

     TEST(Lamparendszer, classtest)
        {

            Lamparendszer r;
            r.init();

            EXPECT_EQ((Allapot)Init, r.getAllapot()) << "Rossz allapot" << endl;
            r.kovAllapot();
            EXPECT_EQ((Allapot)All1, r.getAllapot()) << "Rossz allapot" << endl;
            r.kovAllapot();
            EXPECT_EQ((Allapot)All2, r.getAllapot()) << "Rossz allapot" << endl;
            r.kovAllapot();
            EXPECT_EQ((Allapot)All3, r.getAllapot()) << "Rossz allapot" << endl;
            r.kovAllapot();
            EXPECT_EQ((Allapot)All4, r.getAllapot()) << "Rossz allapot" << endl;
            r.kovAllapot();
            EXPECT_EQ((Allapot)All1, r.getAllapot()) << "Rossz allapot" << endl;
        }
    ENDM
// Erzekolok
    TEST(Erzekelok, classtest)
        {

            Erzekelok e;
            EXPECT_EQ((int)0, e.getSzamlalo()) << "Rossz szamalalo ertek" << endl;
            Auto a(1,0,0,2);

            for (int i = 0; i <5; ++i) {
                a.halad();
            }

            EXPECT_EQ((int)20, a.getPoz()) << "Rossz haladasi ertek" << endl;

            e.vizsgal(&a);

            EXPECT_EQ((int)1, e.getSzamlalo()) << "Rossz szamlalo ertek" << endl;

            for (int i = 0; i <15; ++i) {
                a.halad();
            }
            EXPECT_EQ((int)80, a.getPoz()) << "Rossz haladasi ertek" << endl;
            e.vizsgal(&a);
            EXPECT_EQ((int)0, e.getSzamlalo()) << "Rossz szamlalo ertek" << endl;
        }
    ENDM
}
