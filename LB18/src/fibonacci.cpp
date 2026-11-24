#include "fibonacci.h"

// Итеративная проверка: перебираем числа Фибоначчи, пока не достигнем n.
// long long защищает от переполнения при больших n.
bool isFibonacci(int n) {
    if (n < 0) return false;
    long long a = 0, b = 1;
    while (a < n) {
        long long next = a + b;
        a = b;
        b = next;
    }
    return a == n;
}