#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "filmy.h"
#include "vector.h"

using namespace std;

Vector vector1;

string odwroc_stringa(string tekst){
    int dlugoscTekstu = tekst.length();
    for(int i = 0; i < (dlugoscTekstu/2); i++){
        swap(tekst[i],tekst[dlugoscTekstu - 1 - i]);
    }
    return tekst;
}
void rozdzielenie_danych(string liniaTekstu){

    string tytul;
    float ocena;
    string ocenaString = "";
    int dlugoscLiniTekstu = liniaTekstu.length();
    int i = dlugoscLiniTekstu - 1;

    while(liniaTekstu[i] != '0'){
        i--;
    }

    while(liniaTekstu[i] != ','){
        ocenaString = ocenaString + liniaTekstu[i];
        i--;
    }
    ocenaString = odwroc_stringa(ocenaString);
    ocena = stof(ocenaString);

    for(int j = 0; j <= i; j++){
        tytul = tytul + liniaTekstu[j];
    }

    vector1.dodajFilm(tytul, ocena);
}
void wczytywanie_danych( int ile_danych_wczytac){

    ifstream File;
    File.open("E:/studia/sem 4/Analiza algorytmow/projekt 1/program/projekt2_dane.csv");

    string tekst;
    getline(File, tekst);
    for(int i = 0; i < ile_danych_wczytac; i++){
        getline(File, tekst);
        rozdzielenie_danych(tekst);
    }

    File.close();

}
int main(){
    int ileDanychWczytac = 0;
    cout << "Ile danych wczytac (max 1010291): ";
    cin >> ileDanychWczytac;

    wczytywanie_danych(ileDanychWczytac);

    vector1.wyswietlFilmy();

    int wyborSortowania;
    cout << endl;
    cout << "Wybierz jak posortowac: " << endl;
    cout << "1. MergeSort" << endl;
    cout << "2. QuickSort" << endl;
    cout << "3. Kubelkowe" << endl;
    cout << "Twoj wybor:";
    cin >> wyborSortowania;

    switch(wyborSortowania){
        case 1:
            vector1.MergeSort(0, ileDanychWczytac - 1);
            break;
        case 2:
            vector1.QuickSort(0, ileDanychWczytac - 1);
            break;
        case 3:
            vector1.BucketSort(ileDanychWczytac);
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
            break;
    }

    cout << endl;
    cout << "Posortowane: " << endl;

    vector1.wyswietlFilmy();
    return 0;
}