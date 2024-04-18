#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>
#include <cstring>

using namespace std;

class Osoba {
private:
    char nazwisko[50];

public:
    Osoba(const char* nazwisko = "") { 
        strncpy_s(this->nazwisko, nazwisko, sizeof(this->nazwisko)-1); 
        this->nazwisko[sizeof(this->nazwisko) - 1] = '\0';
    }

    friend ostream& operator<<(ostream& out, const Osoba& osoba) {
        out << osoba.nazwisko;
        return out;
    }
    friend ostream& operator<<(ostream& out, const Osoba* osoba) {
        out << osoba->nazwisko;
        return out;
    }
};

#endif