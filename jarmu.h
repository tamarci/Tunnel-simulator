//
// Created by Marci on 2020. 04. 15..
//

#ifndef NAGYHAZI2_JARMU_H
#define NAGYHAZI2_JARMU_H

#include "Idopont.h"
#include "enums.h"
//#include "memtrace.h"

class Jarmu {
    int id;
    int poz;
    bool irany;
    Idopont erkezes;
    bool mozgasban;

protected:
    int speed;
    Idopont gyorsitas;

public:

    Jarmu(int id, bool irany, const Idopont &erk, const Idopont &gyors);

    int getId(){
        return  id;
    }

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

    bool isMozgasban() const{
        return mozgasban;
    }

    Idopont getErkezes() const {
        return erkezes;
    }

    virtual void changeSpeed() = 0;

    void setMozgasban(bool megy);

    void setPoz(int pozv);

    void halad();

    bool atlep(int poz);

    virtual void kiir() = 0;

    virtual ~Jarmu(){}

};

class Auto : public Jarmu {
    int utasokszama;
public:
    Auto(int id, bool irany = true, const Idopont &erk = 0, const Idopont &gyors = 0, int utasok = 2);

    virtual void changeSpeed();

    virtual void kiir();

};

class Motor : public Jarmu {
    int maxSpeed;
public:
    Motor(int id, bool irany = true, const Idopont &erk = 0, Idopont gyors = 0, int max = 10);

    virtual void changeSpeed();

    virtual void kiir();


};

class Truck : public Jarmu {
    int tomeg;
public:


    Truck(int id, bool irany = true, const Idopont &erk = 0, const Idopont &gyors = 0, int m = 100);

    virtual void changeSpeed();

    virtual void kiir();


};

#endif //NAGYHAZI2_JARMU_H
