//
// Created by Marci on 2020. 04. 24..
//

#include "lampak.h"
//#include "memtrace.h"
void Lamparendszer::kovAllapot(){
    switch (allapot) {
        case (Init) :
            allapot = All1;
            l1.szintVallt();
            break;
        case (All1) :
            allapot = All2;
            l1.szintVallt();
            break;
        case (All2) :
            allapot = All3;
            l2.szintVallt();
            break;
        case (All3) :
            allapot = All4;
            l2.szintVallt();
            break;
        case (All4) :
            allapot = All1;
            l1.szintVallt();
            break;
    }
}

void Lamparendszer::init() {
    allapot = Init;
}