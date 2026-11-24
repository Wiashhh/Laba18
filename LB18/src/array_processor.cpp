#include "array_processor.h"
#include "fibonacci.h"
#include "math_utils.h"

long long processArray(int* a, int n, int& replacedCount, int& overflowCount) {
    long long sum = 0;
    replacedCount = 0;
    overflowCount = 0;
    for (int i = 0; i < n; ++i) {
        if (!isFibonacci(a[i])) continue;
        int fact = 0;
        if (factorial(a[i], fact)) {
            a[i] = fact;
            sum += fact;
            ++replacedCount;
        } else {
            ++overflowCount; // факториал не помещается в int — элемент не меняем
        }
    }
    return sum;
}