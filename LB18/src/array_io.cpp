#include "array_io.h"
#include <iostream>

int* createArray(int n) {
    return new int[n];
}

void deleteArray(int* a) {
    delete[] a;
}

bool inputArray(int* a, int n) {
    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) return false;
    }
    return true;
}

void printArray(const int* a, int n, const char* title) {
    std::cout << title << ": ";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}