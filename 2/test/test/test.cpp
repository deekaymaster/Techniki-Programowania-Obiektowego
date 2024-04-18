// Zad2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;

template <typename T, typename Ts>

Ts suma(Ts a, T b) {
    return a + b;
}

template <typename T>

class Test {
public:
    T x;
    T y;
    void wpisz() {
        cout << "Podaj x: " << endl;
        cin >> x;
        cout << "Podaj y: " << endl;
        cin >> y;
    }
    void wypisz() {
        cout << "x + y = " << x + y << endl;
    }
};

int main()
{
    double a = 5, b = 6.6;
    cout << suma(a, b) << endl;

    int c = 5, d = 10;
    cout << suma(c, d) << endl;

    cout << suma(b, d) << endl;

    Test <int> t1;
    t1.wpisz();
    t1.wypisz();

    Test <double> t2;
    t2.wpisz();
    t2.wypisz();


    Test <string> t3;
    t3.wpisz();
    t3.wypisz();

    return 0;
}