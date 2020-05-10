//
// Created by Marci on 2020. 05. 01..
//

#ifndef NAGYHAZI2_FORGALOM_H
#define NAGYHAZI2_FORGALOM_H

#include <vector>
#include "jarmu.h"


class Forgalom {
    std::vector<Jarmu *> jarmuvek;
public:
    Forgalom() {}

    Forgalom(const Forgalom &f) {
        for (int i = 0; i < jarmuvek.size(); ++i) {
            jarmuvek.push_back(f.jarmuvek[i]->clone());
        }
    }

    Forgalom &operator=(const Forgalom &f) {
        if (&f != this) {
            for (size_t i = 0; i < jarmuvek.size(); ++i) {
                delete jarmuvek[i];
            }

            for (size_t i = 0; i < jarmuvek.size(); ++i) {
                jarmuvek[i] = f.jarmuvek[i]->clone();
            }
        }
        return *this;
    }

    void hozzad(Jarmu *a) {
        jarmuvek.push_back(a);
    }

    void minden_kiir() {
        for (int i = 0; i < jarmuvek.size(); ++i) {
            jarmuvek[i]->kiir();
        }
    }

    void minden_halad() {
        for (int i = 0; i < jarmuvek.size(); ++i) {
            jarmuvek[i]->halad();
        }
    }

    int keres() {
        int osszmod = 0;
        for (int i = 0; i < jarmuvek.size(); ++i) {
            if (true)
                jarmuvek[i]->kiir();

        }
        return osszmod;
    }

    void torol(size_t idx) {
        delete jarmuvek[idx];
        jarmuvek.erase(jarmuvek.begin() + idx);
    }

    void kovAllapot(Idopont ido, Allapot all){
        for (int i = 0; i < jarmuvek.size(); ++i) {

            if(jarmuvek[i]->getPoz()<0||jarmuvek[i]->getPoz()>100)
                    torol(i);

            else {

                if(ido==jarmuvek[i]->getErkezes())
                    jarmuvek[i]->setMozgasban(true);

                if (ido == jarmuvek[i]->getGyorsitas())
                    jarmuvek[i]->changeSpeed();

                if(( all!=All1 && jarmuvek[i]->isIrany() && jarmuvek[i]->getPoz()+jarmuvek[i]->getSpeed()>erz1.getPoz()) ||(all!=All3 && !jarmuvek[i]->isIrany() && jarmuvek[i]->getPoz()-jarmuvek[i]->getSpeed()<erz1.getPoz()))
                    jarmuvek[i]->setMozgasban(false);

                //ebbol valahogy ki is kell jönnie ha ujra zold lesz neki
                // erzekelo problemat meg kell oldani

                if(jarmuvek[i]->isMozgasban())
                    jarmuvek[i]->halad();
            }
        }

    }

    ~Forgalom() {
        for (int i = 0; i < jarmuvek.size(); ++i) {
            delete jarmuvek[i];
        }
    }

};

#endif //NAGYHAZI2_FORGALOM_H
