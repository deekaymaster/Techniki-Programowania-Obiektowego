// Odwróć kolejność elementów w tablicy z pomocą stosu
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    const int size = 10;
    int array[size];

    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(nullptr));

    // Losowanie i wypełnianie tablicy
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100; // Losowanie liczby od 0 do 99
    }

    //Wyświetlanie elementów tablicy
    cout << "Elementy tablicy przed zamiana kolejnosci:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }

    stack<int> myStack;

    for (int i = 0; i < size; ++i) {
        myStack.push(array[i]);
    }

    for (int i = 0; i < size; ++i) {
        array[i] = myStack.top();
        myStack.pop();
    }

    //Wyświetlanie elementów tablicy
    cout << "Elementy tablicy po zamianie kolejnosci:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << array[i] << endl;
    }

}
