//
// Created by Marci on 2020. 04. 15..
//

#ifndef NAGYHAZI2_JARMU_H
#define NAGYHAZI2_JARMU_H

#include "Idopont.h"
#include "enums.h"
//#include "memtrace.h"

class Jarmu {
    int poz;
    bool irany;
    Idopont erkezes;

protected:
    int speed;
    Idopont gyorsitas;
public:

    Jarmu(bool irany, const Idopont &erk, const Idopont &gyors);

    Jarmu(const Jarmu &j);

    int getPoz() const {
        return poz;
    }

    int getSpeed() const {
        return speed;
    }

    Idopont getGyorsitas() const {
        return gyorsitas;
    }

    bool isIrany() const {
        return irany;
    }

    Idopont getErkezes() const {
        return erkezes;
    }

    virtual void changeSpeed() = 0;

    void halad();

    bool checkLampa(Allapot all);

    virtual void kiir() = 0;

    virtual Jarmu *clone() = 0;

    virtual ~Jarmu() {}
};

class Auto : public Jarmu {
    int utasokszama;
public:
    Auto(bool irany = true, const Idopont &erk = 0, const Idopont &gyors = 0, int utasok = 2);

    int getUtasokszama() const;

    virtual void changeSpeed();

    virtual void kiir();

    virtual Jarmu *clone();

    ~Auto() {}
};

class Motor : public Jarmu {
    int maxSpeed;
public:
    Motor(bool irany = 1, const Idopont &erk = 0, Idopont gyors = 0, int max = 10);

    int getMaxSpeed() const;

    virtual void changeSpeed();

    virtual void kiir();

    virtual Jarmu *clone();

    ~Motor() {}
};

class Truck : public Jarmu {
    int tomeg;
public:


    Truck(bool irany = true, const Idopont &erk = 0, const Idopont &gyors = 0, int m = 100);


    int getTomeg() const;

    virtual void changeSpeed();

    virtual void kiir();

    virtual Jarmu *clone();

    ~Truck() {}
};

#endif //NAGYHAZI2_JARMU_H
