#include "tipo.h"
#include "liste.h"
#include <iostream>
#include <fstream>

using namespace std;

void pesca(lista &l){
    tipo_inf nuovo;
    cout<<"Inserisci una nuova carta valore seme: ";
    cin>>nuovo.valore>>nuovo.seme;
    lista e = new_elem(nuovo);
    l = ord_insert_elem(l,e);
}

void pescaFile(lista &l, int n, char file[]){
    ifstream f(file);
    tipo_inf nuovo;
    for(int i=0;i<n;i++){
        f>>nuovo.valore>>nuovo.seme;
        lista e = new_elem(nuovo);
        l = ord_insert_elem(l,e);
    }
}

void stampa(lista l){
    while(l != NULL){
        print(head(l));
        cout<<" ";
        l = tail(l);
    }
}

int main(){
    lista g1 = NULL, g2 = NULL;
    /*cout<<"Carte per il giocatore 1: ";
    for(int i=0;i<6;i++)
        pesca(g1);
    cout<<endl<<"Carte per il giocatore 2: ";
    for(int i=0;i<6;i++)
        pesca(g2);*/
    pescaFile(g1, 6, "card1.txt");
    pescaFile(g2, 6, "card2.txt");
    cout<<"Giocatore 1: ";
    stampa(g1);
    cout<<endl<<"Giocatore 2: ";
    stampa(g2);
    cout<<endl;
}