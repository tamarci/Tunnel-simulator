//
// Created by Marci on 2020. 05. 01..
//

#ifndef NAGYHAZI2_FORGALOM_H
#define NAGYHAZI2_FORGALOM_H

#include <vector>
#include "jarmu.h"

//a jarmuvek kezelesehez hasznalt heterogen kollekcio, es kezelese
class Forgalom {
    std::vector<Jarmu *> jarmuvek;
public:
    Forgalom() {}

    size_t getSize();

    void hozzad(Jarmu *a) {
        jarmuvek.push_back(a);
    }

    void minden_kiir();


    int forg_atlep(int poz);

    void torol(size_t idx);

    //minden autora megnezi hogyha a lampanal jar az piros-e
    void lampanal(Allapot all, int poz1, int poz2);

    //jarmuvenkent eldonti hogy az adott idopillanatban minek kell tortennie vele
    void kovAllapot(Idopont ido, Allapot all);

    ~Forgalom();

};

#endif //NAGYHAZI2_FORGALOM_H
