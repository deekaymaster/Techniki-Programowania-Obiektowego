#include "osoba.h"
#include "wektor.h"

using namespace std;

int main() {
    // Tworzenie obiektów klasy Osoba
    Osoba muzyk1("Mozart");
    Osoba muzyk2("Beethoven");
    Osoba fizyk1("Oppenheimer");
    Osoba fizyk2("Einstein");
    Osoba matematyk1("Archimedes");
    Osoba matematyk2("Pitagoras");

    // Tworzenie wektora osób
    Wektor<Osoba> wektor_osob;

    // Wstawianie osób(obiektów) do wektora
    wektor_osob.wstaw(muzyk1);
    wektor_osob.wstaw(muzyk2);
    wektor_osob.wstaw(fizyk1);
    wektor_osob.wstaw(fizyk2);
    wektor_osob.wstaw(matematyk1);
    wektor_osob.wstaw(matematyk2);

    // Wyświetlanie zawartości wektora
    cout << "Zawartosc wektora osob:" << endl;
    cout << wektor_osob << endl;

    // Usuwanie 3 osoby(o indeksie 2) z wektora
    wektor_osob.usun(2);

    // Wyświetlanie zawartości wektora po usunięciu
    cout << "Po usunieciu osoby na indeksie 2:" << endl;
    cout << wektor_osob << endl;

    // Tworzenie wektora liczb zmiennoprzecinkowych
    Wektor<double> wektor_liczb;
    // Wstawianie liczb zmiennoprzecinkowych typu double do wektora
    double tab_liczb[] = { 2.45, -56.78, 0, 25.45, 101.12, -152.32 };
    for (int i = 0;i < (sizeof(tab_liczb) / sizeof(double));i++) {
        wektor_liczb.wstaw(tab_liczb[i]);
    }

    // Wyświetlanie zawartości wektora liczb zmiennoprzecinkowych
    cout << "Zawartosc wektora liczb:" << endl;
    cout << wektor_liczb << endl;

    // Usuwanie 3 liczby(o indeksie 2) z wektora
    wektor_liczb.usun(2);

    // Wyświetlanie zawartości wektora liczb zmiennoprzecinkowych po usunięciu
    cout << "Po usunieciu liczby na indeksie 2:" << endl;
    cout << wektor_liczb << endl;

    // Tworzenie wektora wskaźników na osoba
    Wektor<Osoba *> wektor_wskaznikow;

    // Tworzenie wskaźników na obiekty Osoba
    Osoba* wskaznikNaMuzyk1 = &muzyk1;
    Osoba* wskaznikNaMuzyk2 = &muzyk2;
    Osoba* wskaznikNaFizyk1 = &fizyk1;
    Osoba* wskaznikNaFizyk2 = &fizyk2;
    Osoba* wskaznikNaMatematyk1 = &matematyk1;
    Osoba* wskaznikNaMatematyk2 = &matematyk2;

    // Wstawianie wskaźników na obiekty Osoba do wektora
    wektor_wskaznikow.wstaw(wskaznikNaMuzyk1);
    wektor_wskaznikow.wstaw(wskaznikNaMuzyk2);
    wektor_wskaznikow.wstaw(wskaznikNaFizyk1);
    wektor_wskaznikow.wstaw(wskaznikNaFizyk2);
    wektor_wskaznikow.wstaw(wskaznikNaMatematyk1);
    wektor_wskaznikow.wstaw(wskaznikNaMatematyk2);

    // Wyświetlanie zawartości wektora wskaźników na Osoba
    cout << "Zawartosc wektora wskaznikow:" << endl;
    cout << wektor_wskaznikow << endl;

    // Usuwanie 3 wskaźnika(o indeksie 2) z wektora
    wektor_wskaznikow.usun(2);

    // Wyświetlanie zawartości wektora wskaźników na Osoba po usunięciu 3 wskaźnika
    cout << "Po usunieciu wskaznika na indeksie 2:" << endl;
    cout << wektor_wskaznikow << endl;
    return 0;
}