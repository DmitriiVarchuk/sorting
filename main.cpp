#include <iostream>
#include <random>
using namespace std;

void insert_sort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void random_array(int* arr, int size) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < size; i++) {
        arr[i] = dist(mt);
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
    insert_sort(arr, size);
    cout << "After" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}