//
// Created by Marci on 2020. 04. 24..
//

#ifndef NAGYHAZI2_IDOPONT_H
#define NAGYHAZI2_IDOPONT_H

#include <iostream>
#include <iomanip>
//#include "memtrace.h"

class Idopont{
    int ido;
public:
    Idopont(int n = 0);

    Idopont(const Idopont& i) {
        ido = i.ido;
    }

   void telik(){ ido++;}

   int getIdo() const { return ido; }

   bool operator==(const Idopont& other){
        return ido==other.ido;
    }

    bool operator<=(const Idopont& other){
        return ido<=other.ido;
    }
    bool operator>=(const Idopont& other){
        return ido>=other.ido;
    }
    ~Idopont(){}
};

std::ostream& operator<<(std::ostream& os, const Idopont& i );
std::istream& operator>>(std::istream& is, Idopont& i );
#endif //NAGYHAZI2_IDOPONT_H
