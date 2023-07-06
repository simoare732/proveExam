#include "tipo.h"
#include "liste.h"
#include <iostream>
#include <fstream>

using namespace std;

void pesca(lista &l){
    tipo_inf nuovo;
    cout<<"Pesca ";
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

carta * scala(lista carte, int&  lunghezza){
    carta* c = NULL;
    lunghezza = 1;
    bool trovato = false;
    while(carte!= NULL && tail(carte) != NULL && !trovato){
        if(head(tail(carte)).seme == head(carte).seme && head(tail(carte)).valore == head(carte).valore+1){
            if(c == NULL)
                c = &carte->inf;
            lunghezza++;
        }
        else{
            if(lunghezza >= 3)
                trovato = true;
            else{ 
                c = NULL;
                lunghezza = 1;
            }
        }
        carte = tail(carte);
    }
    return c;
}

carta* best_scala(lista carte, int& lunghezza){
    int tmpn=0, max=0;
    carta* tmpc = NULL;
    carta* maxlc = NULL;
    do{
        tmpc = scala(carte, tmpn);
        if(tmpc != NULL && tmpn > max){
            max = tmpn;
            maxlc = tmpc;
        }
        if(tmpc != NULL){
            lista e = search(carte, *tmpc);
            for(int i=0;i<tmpn && e != NULL;i++)
                e = tail(e);
            carte = e;
        }   

    }while(tmpc != NULL && carte != NULL);
    lunghezza = max;
    return maxlc;
}

int cala(lista &carte){
    int lung;
    carta *c = best_scala(carte,lung);
    if(c == NULL)
        return 0;
    lista e = search(carte, *c);
    int punteggio = 0;
    for(int i=0;i<lung;i++){
        print(head(e));
        punteggio += head(e).valore;
        cout<<" ";
        lista tmp = e;
        e=tail(e);
        carte = delete_elem(carte, tmp);
    }
    return punteggio;
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
    int lung;
    cout<<"Giocatore 1: ";
    lista e = search(g1, *scala(g1, lung));
    for(int i=0;i<lung;i++){
        print(head(e));
        cout<<" ";
        e=tail(e);
    }
    cout<<endl<<"Giocatore 2: ";
    lista e1 = search(g2, *scala(g2, lung));
    for(int i=0;i<lung;i++){
        print(head(e1));
        cout<<" ";
        e1=tail(e1);
    }
    cout<<endl<<endl;
    int mano = 1;
    int punt1 = 0, punt2=0;
    bool turno = true;
    while(g1 != NULL && g2 != NULL){
        if(turno){
            cout<<"Mano "<<mano<<endl<<"Giocatore 1: ";
            mano++;
            pesca(g1);
            cout<<"Cala: ";
            punt1 += cala(g1);
            cout<<"Carte in mano: ";
            stampa(g1);
            cout<<" Punteggio: "<<punt1<<endl;
            turno = false;
        }
        else{
            cout<<"Giocatore 2: ";
            pesca(g2);
            cout<<"Cala: ";
            punt2 += cala(g2);
            cout<<"Carte in mano: ";
            stampa(g2);
            cout<<" Punteggio: "<<punt2<<endl;
            turno = true;
        }
        
    }
    cout<<"Fine gioco! ";
    cout<<"Vince il gioco il Giocatore ";
    if(punt1 > punt2)
        cout<<"1 con "<<punt1<<" punti"<<endl;
    else  cout<<"2 con "<<punt2<<" punti"<<endl;  
    
    
}