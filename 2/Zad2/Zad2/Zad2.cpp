#include <iostream>

using namespace std;

template <typename T>
void wypisz(T *wsk) {
    cout << "Wartosc wskazywana przez wskaznik to " << *wsk << endl;
}

int main()
{
    double x = 1500.25;
    double* wsk1 = &x;
    int y = 5;
    int* wsk2 = &y;

    wypisz(wsk1);
    wypisz(wsk2);
}
