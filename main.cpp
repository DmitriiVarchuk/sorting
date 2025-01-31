#include <iostream>
#include <random>
using namespace std;

void random_array(int* arr, int size) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
    }
}

void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // about swap i seen in internet
            }
        }
    }
}

int main() {
    int size;
    cout << "Size of array: ";
    cin >> size;
    int* arr = new int[size];
    random_array(arr, size);

    cout << "Before" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, size);

    cout << "After" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}