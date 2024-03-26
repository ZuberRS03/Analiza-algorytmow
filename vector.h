#ifndef PROGRAM_VECTOR_H
#define PROGRAM_VECTOR_H

#include <iostream>
#include <vector>
#include "filmy.h"

class Vector {
    private:
        std::vector<filmy> vector1;

    public:
        Vector() {}

        void dodajFilm(std::string tytul, float ocena);

        void wyswietlFilmy();

        void MergeSort(int pierwsza, int ostatnia);

        void QuickSort(int pierwsza, int ostatnia);

        void BucketSort(int ileLiczb);

};


#endif //PROGRAM_VECTOR_H
