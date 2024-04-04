#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "filmy.h"
#include "vector.h"

using namespace std;
clock_t start, stop;

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

    while(liniaTekstu[i] != '0' and liniaTekstu[i] != ','){
        i--;
    }
    if(liniaTekstu[i] == '0'){
        while(liniaTekstu[i] != ','){
            ocenaString = ocenaString + liniaTekstu[i];
            i--;
        }
        ocenaString = odwroc_stringa(ocenaString);
        ocena = stof(ocenaString);
    } else if(liniaTekstu[i] == ',') {
        ocena = -1;
    }

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
int usun_puste(Vector& vec) {
    int licznikUsunientych = 0;
    for(int i = 0; i < vec.size();) {
        if(vec.getOcenaFloat(i) == -1) {
            vec.usuwanieFilmu(i);
            licznikUsunientych++;
        } else {
            i++;
        }
    }
    return licznikUsunientych;
}
int main(){
    int ileDanychWczytac = 0;
    cout << "Ile danych wczytac (max 1010291): ";
    cin >> ileDanychWczytac;

    double czasWczytywania = 0;
    cout << "Wczytywanie danych..." << endl;
    start = clock();
    wczytywanie_danych(ileDanychWczytac);
    stop = clock();
    czasWczytywania = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Dane wczytane" << endl;
    cout << endl;
    //vector1.wyswietlFilmy();

    double czasUsuwania = 0;
    int ileDanych = ileDanychWczytac;
    cout << "Usuwanie pustych danych..." << endl;
    start = clock();
    ileDanych = ileDanychWczytac - usun_puste(vector1);
    stop = clock();
    czasUsuwania = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Puste dane usuniete" << endl;

    //vector1.wyswietlFilmy();

    int wyborSortowania;
    cout << endl;
    cout << "Wybierz jak posortowac: " << endl;
    cout << "1. MergeSort" << endl;
    cout << "2. QuickSort" << endl;
    cout << "3. Kubelkowe" << endl;
    cout << "Twoj wybor:";
    cin >> wyborSortowania;

    double czasSortowania = 0;
    switch(wyborSortowania){
        case 1:
            start = clock();
            vector1.MergeSort(0, ileDanych - 1);
            stop = clock();
            czasSortowania = (double)(stop - start) / CLOCKS_PER_SEC;
            break;
        case 2:
            start = clock();
            vector1.QuickSort(0, ileDanych - 1);
            stop = clock();
            czasSortowania = (double)(stop - start) / CLOCKS_PER_SEC;
            break;
        case 3:
            start = clock();
            vector1.BucketSort(ileDanych);
            stop = clock();
            czasSortowania = (double)(stop - start) / CLOCKS_PER_SEC;
            break;
        default:
            cout << "Nie ma takiej opcji" << endl;
            break;
    }

    cout << endl;
    cout << "Posortowano" << endl;

    //vector1.wyswietlFilmy();
    sprawdzenie:
    cout << endl;
    cout << "Czy sprawdzic? (1 - tak, 0 - nie): ";
    int spr;
    cin >> spr;
    if(spr == 1){
        if(vector1.czyPosortowane() == true){
            cout << "Posortowane poprwnie" << endl;
        } else{
            cout << "Blad w sortowaniu" << endl;
        }
    } else if(spr == 0){
        cout << endl;
    } else{
        cout << "Nie ma takiej opcji, wybierz \"1\" lub \"0\":" << endl;
        goto sprawdzenie;
    }
    cout << "Czas wczytywania danych: " << czasWczytywania << "s" << endl;
    cout << "Czas usuwania pustych danych: " << czasUsuwania << "s" << endl;
    cout << "Czas sortowania: " << czasSortowania << "s" << endl;

    cout << "Mediana: " << vector1.mediana() << endl;
    cout << "Srednia: " << vector1.srednia() << endl;

    return 0;
}