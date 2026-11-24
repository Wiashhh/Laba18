#include "math_utils.h"
#include <climits>

// Рекурсивная функция факториала с контролем переполнения.
bool factorial(int n, int& result) {
    if (n < 0) {
        return false; // факториал отрицательного числа не определён
    }
    if (n == 0 || n == 1) {
        result = 1;
        return true;
    }
    int prev = 0;
    if (!factorial(n - 1, prev)) {
        return false; // переполнение на более глубоком уровне рекурсии
    }
    long long cur = static_cast<long long>(prev) * n;
    if (cur > INT_MAX) {
        return false; // переполнение int
    }
    result = static_cast<int>(cur);
    return true;
}