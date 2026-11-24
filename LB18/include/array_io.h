#ifndef ARRAY_IO_H
#define ARRAY_IO_H

// Модуль ввода/вывода массивов.

// Выделяет память под массив из n элементов.
int* createArray(int n);

// Освобождает память массива.
void deleteArray(int* a);

// Ввод n элементов с клавиатуры. Возвращает false при ошибке ввода.
bool inputArray(int* a, int n);

// Вывод массива на экран с заголовком.
void printArray(const int* a, int n, const char* title);

#endif