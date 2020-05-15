//
// Created by Marci on 2020. 04. 26..
//

#include "jarmu.h"
//#include "memtrace.h"

Jarmu::Jarmu(int id,bool irany, const Idopont &erk, const Idopont &gyors) : id(id), irany(irany), erkezes(erk), gyorsitas(gyors) {
    if (irany)
        poz = 0;
    else
        poz = 100;
    speed = 4;
    mozgasban = false;
}

// egy masodpercnyit mozog a mozgasi iranyaba a jarmu
void Jarmu::halad() {
    if (irany)
        poz += speed;
    else
        poz -= speed;
}

// beallitja a jarmu mozgas allapotat
//ha nincs mozgasban akkor nem fog elore haladni a kovetkezo mp-ben
void Jarmu::setMozgasban(bool megy) {
    mozgasban = megy;
}

//a jarmu a pirosnal megall, a fv segitsegevel allitja be a poziciot
void Jarmu::setPoz(int pozv) {
    poz=pozv;
}

//megnezi, hogy az auto atlepi-e a megadott koo.-t a következo mp-ben
bool Jarmu::atlep(int pozv) {
    if (mozgasban) {    //csak akkor van ertelme ezt vizsgalni ha azt auto mozog
        if (irany) { //egyik irany
            if (poz <= pozv && poz + speed > pozv)
                return true;                    //ez logikailag egyszerusitheto lenne, de az atlathatosag kedveert meghagyom igy
        } else { //masik irany
            if (poz >= pozv && poz - speed < pozv)
                return true;
        }
    }
    return false;
}


Motor::Motor(int id,bool irany, const Idopont &erk, Idopont gyors, int max) : Jarmu(id,irany, erk, gyors),
                                                                       maxSpeed(max) {}
//adig gyorsit mig el nem eri a may sebesseget
void Motor::changeSpeed() {
    if (speed + 4 <= maxSpeed)
        speed += 4;
    else speed = maxSpeed;
}

//kiirja az osszes adatat
void Motor::kiir() {
    std::cout << "M " <<getId()<<". poz: " << getPoz() << " dir: " << isIrany() << " speed: " << getSpeed() << ' ' << getErkezes() << ' '
              << getGyorsitas() << " maxspeed: " << maxSpeed << std::endl;
}


//Auto fv-nyei
Auto::Auto(int id,bool irany, const Idopont &erk, const Idopont &gyors, int utasok)
        : Jarmu(id, irany, erk, gyors), utasokszama(utasok) {
    if (utasok < 1 || utasok > 5) {
        std::cout << "Hibas utasszam";
        utasok = 2;
    }
}

//az utasok szamatol fuggoen gyorsit, lassit
void Auto::changeSpeed() {
    if (utasokszama > 2)
        speed -= utasokszama;
    else speed += utasokszama;

    if (speed < 2)
        speed = 2;
}



void Auto::kiir() {
    std::cout << "A " <<getId()<<". poz: " << getPoz() << " dir: " << isIrany() << " speed: " << getSpeed() << ' ' << getErkezes() << ' '
              << getGyorsitas() << " utasoksz.: " << utasokszama << std::endl;
}


//teherauto fv-nyei
Truck::Truck(int id, bool irany, const Idopont &erk, const Idopont &gyors, int m) : Jarmu(id, irany, erk, gyors),
                                                                            tomeg(m) {}
//tomegetol fugg a gyorsitas merteke
void Truck::changeSpeed() {
    speed += (2 * (100 / tomeg));
}


void Truck::kiir() {
    std::cout << "T " <<getId()<<". poz: " << getPoz() << " dir: " << isIrany() << " speed: " << getSpeed() << ' ' << getErkezes() << ' '
              << getGyorsitas() << " tom.: " << tomeg << std::endl;
}

