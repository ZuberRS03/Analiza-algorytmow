#ifndef PROGRAM_FILMY_H
#define PROGRAM_FILMY_H

#include <iostream>

using namespace std;

class filmy {
protected:

    string tytul;
    float ocena;

public:

    void setTytul(string Tytul);
    string getTytul();
    void setOcena(float Ocena);
    float getOcena();

};


#endif //PROGRAM_FILMY_H
