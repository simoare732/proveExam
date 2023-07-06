#include "tipo.h"
#include "liste.h"
#include <iostream>

using namespace std;

void pesca(lista &l){
    tipo_inf nuovo;
    cout<<"Inserisci una nuova carta valore seme: ";
    cin>>nuovo.valore>>nuovo.seme;
    lista e = new_elem(nuovo);
    l = ord_insert_elem(l,e);
}

void stampa(lista l){
    while(l != NULL){
        print(head(l));
        cout<<" ";
        l = tail(l);
    }
}