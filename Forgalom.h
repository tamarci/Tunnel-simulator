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
        for (size_t i = 0; i < jarmuvek.size(); ++i) {
            jarmuvek[i]->kiir();
        }
    }


    int fatlep(int poz) { //osszeszamolja hogy a jarmuvek kozul hanyan fognak atlepni egy pontot
        int ossz = 0;
        for (size_t i = 0; i < jarmuvek.size(); ++i) {
            if(jarmuvek[i]->atlep(poz))
                ossz++;
        }
        return ossz;
    }

    void torol(size_t idx) {
        delete jarmuvek[idx];
        jarmuvek.erase(jarmuvek.begin() + idx);
    }


void lampanal(Allapot all, int poz1,int poz2) {
    for (size_t i = 0; i < jarmuvek.size(); ++i) {

        if (all != All1 && jarmuvek[i]->atlep(poz1)){ //logikai irany tesztek kellenek

            jarmuvek[i]->setPoz(poz1 - 1);
            jarmuvek[i]->setMozgasban(false);

        }
        else if(all != All3 && jarmuvek[i]->atlep(poz2)) { //pozitiv iranyu kocsi atlepi ezt Mert all1,2ben van és megall??

            jarmuvek[i]->setPoz(poz2 + 1);
            jarmuvek[i]->setMozgasban(false);

        }

        if ((all == All1 && jarmuvek[i]->isIrany() && (jarmuvek[i]->getPoz() == poz1- 1)) ||
                   (all == All3 && !jarmuvek[i]->isIrany() && (jarmuvek[i]->getPoz() == poz2 + 1))) {
            jarmuvek[i]->setMozgasban(true);
        }



    }
}

    void kovAllapot(Idopont ido, Allapot all){
        for (size_t i = 0; i < jarmuvek.size(); ++i) {

            if(jarmuvek[i]->getPoz()<0||jarmuvek[i]->getPoz()>100)
                    torol(i);

            else {

                if(ido==jarmuvek[i]->getErkezes())
                    jarmuvek[i]->setMozgasban(true);

                if (ido == jarmuvek[i]->getGyorsitas())
                    jarmuvek[i]->changeSpeed();

                if(jarmuvek[i]->isMozgasban())
                    jarmuvek[i]->halad();
            }
        }

    }

    ~Forgalom() {
        for (size_t i = 0; i < jarmuvek.size(); ++i) {
            delete jarmuvek[i];
        }
    }

};

#endif //NAGYHAZI2_FORGALOM_H
