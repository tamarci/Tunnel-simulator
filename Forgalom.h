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
        if(ossz==1){
            std::cout<<"sikerult egyet megszamolni valamerre"<<std::endl;
        }
        return ossz;
    }

    void torol(size_t idx) {
        delete jarmuvek[idx];
        jarmuvek.erase(jarmuvek.begin() + idx);
    }


void lampanal(Allapot all, int poz1,int poz2) {
    for (size_t i = 0; i < jarmuvek.size(); ++i) {

        if (all != All1 && jarmuvek[i]->isIrany() && jarmuvek[i]->atlep(poz1)){ //logikai irany tesztek kellenek

            jarmuvek[i]->setPoz(poz1 - 1);
            jarmuvek[i]->setMozgasban(false);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu megallt a pirosnal (l1)" << std::endl;

        }
        else if(all != All3 && !jarmuvek[i]->isIrany()  && jarmuvek[i]->atlep(poz2)) {

            jarmuvek[i]->setPoz(poz2 + 1);
            jarmuvek[i]->setMozgasban(false);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu megallt a pirosnal (l2)" << std::endl;
        }

        if (all == All1 && jarmuvek[i]->isIrany() && (jarmuvek[i]->getPoz() == poz1- 1))  {

            jarmuvek[i]->setMozgasban(true);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu elindult a pirostol (l1)" << std::endl;

        }
        else if(all == All3 && !jarmuvek[i]->isIrany() && (jarmuvek[i]->getPoz() == poz2 + 1)){

            jarmuvek[i]->setMozgasban(true);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu elindult a pirostol (l2)" << std::endl;
        }



    }
}

    void kovAllapot(Idopont ido, Allapot all){
        for (size_t i = 0; i < jarmuvek.size(); ++i) {

            if(jarmuvek[i]->getPoz()<0||jarmuvek[i]->getPoz()>100) {
                std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu elhagyta a palyat" << std::endl;
                torol(i);
            }
            else {

                if(ido==jarmuvek[i]->getErkezes()) {
                    jarmuvek[i]->setMozgasban(true);
                    std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu megerkezett a palyara" << std::endl;
                }
                if (ido == jarmuvek[i]->getGyorsitas() && ido.getIdo() != 0) {
                    jarmuvek[i]->changeSpeed();
                    std::cout << "Az " << jarmuvek[i]->getId() << ". gyorsit" << std::endl;
                }

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
