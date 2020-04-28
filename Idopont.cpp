//
// Created by Marci on 2020. 04. 26..
//
#include "Idopont.h"
//#include "memtrace.h"
Idopont::Idopont(int n):ido(n) {
int ejfel=23*3600 + 59* 60 + 59;
if (n > ejfel)
ido = n % ejfel;
}

std::ostream& operator<<(std::ostream& os, const Idopont& i ){
    os<< std::setw(2) << std::setfill('0') <<int (i.getIdo()/3600) <<':'<<std::setw(2) << std::setfill('0') << int(i.getIdo()/60)%60 <<':'<<std::setw(2) << std::setfill('0') <<i.getIdo() % 60<< ' ';
    return os;
}
std::istream& operator>>(std::istream& is, Idopont& i ){
    char c;
    int ora,perc, mp;
    is>>ora>>c>>perc>>c>>mp;
    i = Idopont(ora*3600+perc*60+mp);
    return is;
}