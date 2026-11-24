#include <iostream>
#include <limits>
#include "array_io.h"
#include "array_processor.h"

int main() {
    int n = 0;
    std::cout << "Введите размер массива (1..100): ";
    while (true) {
        if (!(std::cin >> n)) {
            if (std::cin.eof()) return 1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Введите число от 1 до 100: ";
            continue;
        }
        if (n >= 1 && n <= 100) break;
        std::cout << "Ошибка ввода. Введите число от 1 до 100: ";
    }

    int* a = createArray(n);
    if (!inputArray(a, n)) {
        std::cout << "Ошибка ввода элементов массива.\n";
        deleteArray(a);
        return 1;
    }

    printArray(a, n, "Исходный массив");

    int replaced = 0, overflow = 0;
    long long sum = processArray(a, n, replaced, overflow);

    printArray(a, n, "Изменённый массив");
    std::cout << "Сумма изменённых элементов: " << sum << "\n";
    std::cout << "Выполнено замен: " << replaced << "\n";
    if (overflow > 0) {
        std::cout << "Пропущено замен (переполнение факториала): " << overflow << "\n";
    }

    deleteArray(a);
    return 0;
}