//
// Created by Marci on 2020. 04. 26..
//

#include "jarmu.h"
//#include "memtrace.h"

Jarmu::Jarmu(bool irany, const Idopont &erk, const Idopont &gyors) : irany(irany), erkezes(erk), gyorsitas(gyors) {
    if (irany)
        poz = 0;
    else
        poz = 100;
    speed = 4;
    mozgasban = false;
}

Jarmu::Jarmu(const Jarmu &j) {
    poz = j.poz;
    irany = j.irany;
    erkezes = j.erkezes;
    speed = j.speed;
    gyorsitas = j.gyorsitas;
}

void Jarmu::halad() {
    if (irany)
        poz += speed;
    else
        poz -= speed;
}

void Jarmu::setMozgasban(bool megy) {
    mozgasban = megy;
}

void Jarmu::setPoz(int pozv) {
    poz=pozv;
}

bool Jarmu::checkLampa(Allapot all) {
    return (irany && all == All1) || (!irany && all == All3);
}

bool Jarmu::atlep(int pozv) {   //megnezi, hogy az auto atlepi-e a megadott koo.-t a következo mp-ben
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


Motor::Motor(bool irany, const Idopont &erk, Idopont gyors, int max) : Jarmu(irany, erk, gyors),
                                                                       maxSpeed(max) {}

void Motor::changeSpeed() {
    if (speed + 4 <= maxSpeed)
        speed += 4;
    else speed = maxSpeed;
}

Jarmu *Motor::clone() {
    return new Motor(*this);
}

void Motor::kiir() {
    std::cout << "M " << getPoz() << ' ' << isIrany() << ' ' << getSpeed() << ' ' << getErkezes() << ' '
              << getGyorsitas() << " " << maxSpeed << std::endl;
}

int Motor::getMaxSpeed() const {
    return maxSpeed;
}

//Auto fv-nyei
Auto::Auto(bool irany, const Idopont &erk, const Idopont &gyors, int utasok)
        : Jarmu(irany, erk, gyors), utasokszama(utasok) {
    if (utasok < 1 || utasok > 5) {
        std::cout << "Hibas utasszam";
        utasok = 2;
    }
}

void Auto::changeSpeed() {
    if (utasokszama > 2)
        speed -= utasokszama;
    else speed += utasokszama;

    if (speed < 1)
        speed = 1;
}

Jarmu *Auto::clone() {
    return new Auto(*this);
}

void Auto::kiir() {
    std::cout << "A " << getPoz() << ' ' << isIrany() << ' ' << getSpeed() << ' ' << getErkezes() << ' '
              << getGyorsitas() << " " << utasokszama << std::endl;
}

int Auto::getUtasokszama() const {
    return utasokszama;
}


//teherauto fv-nyei
Truck::Truck(bool irany, const Idopont &erk, const Idopont &gyors, int m) : Jarmu(irany, erk, gyors),
                                                                            tomeg(m) {}

void Truck::changeSpeed() {
    speed += (2 * (100 / tomeg));
}

Jarmu *Truck::clone() {
    return new Truck(*this);
}

void Truck::kiir() {
    std::cout << "T " << getPoz() << ' ' << isIrany() << ' ' << getSpeed() << ' ' << getErkezes() << ' '
              << getGyorsitas() << " " << tomeg << std::endl;
}

int Truck::getTomeg() const {
    return tomeg;
}
