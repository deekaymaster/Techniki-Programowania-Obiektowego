#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int size) {

    for (int i = 0;i < size;i++) {
        for (int j = 0;j < size-1;j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i=0; i < size;i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}

template <typename T>
void quickSort(T arr[], int size) {
    /*
    *     T pivot = arr[(0 + size - 1) / 2];
    arr[(0 + size - 1) / 2] = arr[size - 1];
    for (j = (0 + size - 1) / 2; i < size - 1;i++) {
        if(arr[i])
    }
    */

}


int main()
{
    const int size = 8;
    int intArray[size] = {12, 3, 56, 24, 8, 2, -14, 100 };
    double doubleArray[size] = { 2.5, 6.7, 1.2, 8.9, 4.3, -5.6, 12.43, -10.9 };
    char charArray[size] = { 'd', 'g', 'a', 'b', 'f', 'x', 'z', 'a'};

    cout << "Tablice posortowane algorytmem babelkowym: " << endl;
    bubbleSort(intArray, size);
    bubbleSort(doubleArray, size);
    bubbleSort(charArray, size);

    cout << "Tablice posortowane algorytmem quicksort: " << endl;
    quickSort(intArray, size);
    quickSort(doubleArray, size);
    quickSort(charArray, size);


}
