//
// Created by Marci on 2020. 05. 16..
//
#include "Forgalom.h"

size_t Forgalom::getSize(){
    return jarmuvek.size();
}

void Forgalom::minden_kiir() {
    for (size_t i = 0; i < jarmuvek.size(); ++i) {
        jarmuvek[i]->kiir();
    }
}

int Forgalom::forg_atlep(int poz) { //osszeszamolja hogy a jarmuvek kozul hanyan fognak atlepni egy pontot
    int ossz = 0;
    for (size_t i = 0; i < jarmuvek.size(); ++i) {
        if(jarmuvek[i]->atlep(poz))
            ossz++;
    }
    if(ossz==1){
        std::cout<<"Valami elhaladt az erzekelok elott"<<std::endl;
    }
    return ossz;
}

void Forgalom::torol(size_t idx) { //torli a megadott elemet
    delete jarmuvek[idx];
    jarmuvek.erase(jarmuvek.begin() + idx);
}

//minden autora megnezi hogyha a lampanal jar az piros-e
void Forgalom::lampanal(Allapot all, int poz1,int poz2) {
    for (size_t i = 0; i < jarmuvek.size(); ++i) {

        if (all != All1 && jarmuvek[i]->isIrany() && jarmuvek[i]->atlep(poz1)){ //logikai irany tesztek kellenek
            //ha pirosuk van megallnak
            jarmuvek[i]->setPoz(poz1 - 1);
            jarmuvek[i]->setMozgasban(false);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu megallt a pirosnal (l1)" << std::endl;

        }
        else if(all != All3 && !jarmuvek[i]->isIrany()  && jarmuvek[i]->atlep(poz2)) {
            //masik iranyba is
            jarmuvek[i]->setPoz(poz2 + 1);
            jarmuvek[i]->setMozgasban(false);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu megallt a pirosnal (l2)" << std::endl;
        }

        if (all == All1 && jarmuvek[i]->isIrany() && (jarmuvek[i]->getPoz() == poz1- 1))  {
            //ha idokezben ujra zold lett akkor elinditja a varakozokat
            jarmuvek[i]->setMozgasban(true);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu elindult a pirostol (l1)" << std::endl;

        }
        else if(all == All3 && !jarmuvek[i]->isIrany() && (jarmuvek[i]->getPoz() == poz2 + 1)){

            jarmuvek[i]->setMozgasban(true);
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu elindult a pirostol (l2)" << std::endl;
        }
    }
}

//jarmuvenkent eldonti hogy az adott idopillanatban minek kell tortennie vele
void Forgalom::kovAllapot(Idopont ido, Allapot all) {
    for (size_t i = 0; i < jarmuvek.size(); ++i) {

        //ha ki lepnek a palyara, torlodnek a frogalombol kollekciobol
        if (jarmuvek[i]->getPoz() < 0 || jarmuvek[i]->getPoz() > 100) {
            std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu elhagyta a palyat" << std::endl;
            torol(i);
        } else {
            //elindulnak
            if (ido == jarmuvek[i]->getErkezes()) {
                jarmuvek[i]->setMozgasban(true);
                std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu megerkezett a palyara" << std::endl;
            }
            //gyorsitanak
            if (ido == jarmuvek[i]->getGyorsitas() && ido.getIdo() != 0) {
                jarmuvek[i]->changeSpeed();
                std::cout << "Az " << jarmuvek[i]->getId() << ". jarmu gyorsit" << std::endl;
            }
            //haladnak
            if (jarmuvek[i]->isMozgasban())
                jarmuvek[i]->halad();
        }
    }
}

Forgalom::~Forgalom() {
    for (size_t i = 0; i < jarmuvek.size(); ++i) {
        delete jarmuvek[i];
    }
}