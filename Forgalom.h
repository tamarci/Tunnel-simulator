//
// Created by Marci on 2020. 05. 01..
//

#ifndef NAGYHAZI2_FORGALOM_H
#define NAGYHAZI2_FORGALOM_H
#include <vector>
#include "Jarmu.h"


class Forgalom{
    std::vector<Jarmu*> jarmuvek;
public:

    Forgalom(const Forgalom &f) {
        for (int i = 0; i < jarmuvek.size(); ++i) {
            jarmuvek.push_back( f.jarmuvek[i]->clone());
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
        int osszmod=0;
        for (int i = 0; i < jarmuvek.size(); ++i) {
            if(true)
                jarmuvek[i]->kiir();

        }
        return osszmod;
    }

    void torol(size_t idx) {
        delete jarmuvek[idx];
        jarmuvek.erase(jarmuvek.begin() + idx);
    }

    ~Forgalom() {
        for (int i = 0; i < jarmuvek.size(); ++i) {
            delete jarmuvek[i];
        }
    }

};
#endif //NAGYHAZI2_FORGALOM_H
