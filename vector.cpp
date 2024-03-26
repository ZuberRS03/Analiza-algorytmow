#include "vector.h"

void Vector::dodajFilm(std::string tytul, float ocena) {
    filmy film;
    film.setTytul(tytul);
    film.setOcena(ocena);
    vector1.push_back(film);
}

void Vector::wyswietlFilmy() {
    for(int i = 0; i < vector1.size(); i++){
        std::cout << vector1[i].getTytul() << " " << vector1[i].getOcena() << std::endl;
    }
}

void scalanie(std::vector<filmy> &vector1, int pierwsza, int srodek, int ostatnia){
    int i, j, k;
    int n1 = srodek - pierwsza + 1;
    int n2 =  ostatnia - srodek;

    std::vector<filmy> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = vector1[pierwsza + i];
    for (j = 0; j < n2; j++)
        R[j] = vector1[srodek + 1+ j];

    i = 0;
    j = 0;
    k = pierwsza;
    while (i < n1 && j < n2)
    {
        if (L[i].getOcena() <= R[j].getOcena())
        {
            vector1[k] = L[i];
            i++;
        }
        else
        {
            vector1[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vector1[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vector1[k] = R[j];
        j++;
        k++;
    }
}
void Vector::MergeSort(int pierwsza, int ostatnia) {
    if(pierwsza < ostatnia){
        int srodek = (pierwsza + ostatnia) / 2;
        MergeSort(pierwsza, srodek);
        MergeSort(srodek + 1, ostatnia);
        scalanie(vector1, pierwsza, srodek, ostatnia);
    }
}

void Vector::QuickSort(int pierwsza, int ostatnia) {
    int i = pierwsza;
    int j = ostatnia;
    float x = vector1[(pierwsza + ostatnia) / 2].getOcena();
    do{
        while(vector1[i].getOcena() < x)
            i++;
        while(vector1[j].getOcena() > x)
            j--;
        if(i <= j){
            std::swap(vector1[i], vector1[j]);
            i++;
            j--;
        }
    } while(i <= j);
    if(pierwsza < j)
        QuickSort(pierwsza, j);
    if(i < ostatnia)
        QuickSort(i, ostatnia);
}

void QuickSortB(std::vector<filmy>::iterator pierwsza, std::vector<filmy>::iterator ostatnia) {
    std::vector<filmy>::iterator i = pierwsza;
    std::vector<filmy>::iterator j = ostatnia;
    float x = (*(pierwsza + (ostatnia - pierwsza) / 2)).getOcena();
    do{
        while((*i).getOcena() < x)
            i++;
        while((*j).getOcena() > x)
            j--;
        if(i <= j){
            std::swap(*i, *j);
            i++;
            j--;
        }
    } while(i <= j);
    if(pierwsza < j)
        QuickSortB(pierwsza, j);
    if(i < ostatnia)
        QuickSortB(i, ostatnia);
}
void Vector::BucketSort(int n) {
    std::vector<filmy> *bucket = new std::vector<filmy>[n + 1];
    cout << "check0\n";
    for(int i = 0; i < n; i++){
        cout << "check1\n";
        int index = n * (vector1[i].getOcena() / 10); //normalizacja oceny
        cout << "check2\n";
        bucket[index].push_back(vector1[i]);
        cout << "check3\n";
    }
    cout << "check4\n";
    for(int i = 0; i <= n; i++){
        cout << "check5\n";
        if (!bucket[i].empty()) {
            cout << "check6\n";
            QuickSortB(bucket[i].begin(), bucket[i].end());
        }
    }
    cout << "check7\n";
    vector1.clear(); // Usuń wszystkie elementy z vector1
    cout << "check7_1\n";
    vector1.resize(n); // Zainicjuj vector1 z odpowiednim rozmiarem

    int index = 0;
    cout << "check8\n";
    for(int i = 0; i <= n; i++){
        cout << "check9\n";
        for(int j = 0; j < bucket[i].size(); j++){
            cout << "check10\n";
            vector1[index++] = bucket[i][j];
            cout << "check11\n";
        }
    }

}
