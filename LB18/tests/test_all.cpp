#include <cassert>
#include <iostream>
#include "math_utils.h"
#include "fibonacci.h"
#include "array_processor.h"

static void testFactorial() {
    int r = -1;
    assert(factorial(0, r) && r == 1);
    assert(factorial(1, r) && r == 1);
    assert(factorial(5, r) && r == 120);
    assert(factorial(12, r) && r == 479001600);
    assert(!factorial(13, r));   // 13! > INT_MAX — переполнение
    assert(!factorial(-3, r));   // отрицательное число
    std::cout << "factorial: OK\n";
}

static void testIsFibonacci() {
    assert(isFibonacci(0));
    assert(isFibonacci(1));
    assert(isFibonacci(2));
    assert(isFibonacci(3));
    assert(isFibonacci(5));
    assert(isFibonacci(8));
    assert(isFibonacci(13));
    assert(isFibonacci(21));
    assert(!isFibonacci(4));
    assert(!isFibonacci(6));
    assert(!isFibonacci(7));
    assert(!isFibonacci(100));
    assert(!isFibonacci(-5));
    std::cout << "isFibonacci: OK\n";
}

static void testProcessArray() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int replaced = 0, overflow = 0;
    long long sum = processArray(a, 6, replaced, overflow);
    assert(a[0] == 1 && a[1] == 2 && a[2] == 6 && a[3] == 4 && a[4] == 120 && a[5] == 6);
    assert(sum == 129);
    assert(replaced == 4 && overflow == 0);

    int b[] = {13, 8, -3, 0};
    sum = processArray(b, 4, replaced, overflow);
    assert(b[0] == 13 && b[1] == 40320 && b[2] == -3 && b[3] == 1);
    assert(sum == 40321);
    assert(replaced == 2 && overflow == 1);
    std::cout << "processArray: OK\n";
}

int main() {
    testFactorial();
    testIsFibonacci();
    testProcessArray();
    std::cout << "Все тесты пройдены\n";
    return 0;
}