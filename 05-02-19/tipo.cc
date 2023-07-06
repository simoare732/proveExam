#include "tipo.h"
#include <iostream>

int compare(tipo_inf t1,tipo_inf t2){
    int diff = (int)t1.seme - (int)t2.seme;
    if (diff != 0) return diff;
    return t1.valore - t2.valore;
}
void copy(tipo_inf& t1,tipo_inf t2){
    t1 = t2;
}
void print(tipo_inf t1){
    std::cout<<t1.valore<<t1.seme;
}