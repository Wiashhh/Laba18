#ifndef ARRAY_PROCESSOR_H
#define ARRAY_PROCESSOR_H

// Модуль обработки массива.

// Заменяет каждый элемент, являющийся числом Фибоначчи, на его факториал.
// Возвращает сумму всех изменённых элементов.
// replacedCount — количество выполненных замен;
// overflowCount — количество замен, пропущенных из-за переполнения факториала.
long long processArray(int* a, int n, int& replacedCount, int& overflowCount);

#endif