#include <iostream>
using namespace std;

template<typename T>

void swapValues(T& a, T& b) {
    T temp = b;
    b = a;
    a = temp;
}

int main()
{
    int a = 2, b = 200;
    cout << "Przed zamiana a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "Po zamianie a = " << a << ", b = " << b << endl;
    return 0;
}
