#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Критерій варіанту 12: елемент парний АБО його індекс не кратний 8
bool Criterion(const int value, const int index)
{
    return value % 2 == 0 || index % 8 != 0;
}

// Заповнення масиву випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Виведення масиву в рядок
void Print(const int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Кількість елементів, що задовольняють критерій
int CountCriterion(const int* a, const int size, int i)
{
    if (i >= size)
        return 0;
    return (Criterion(a[i], i) ? 1 : 0) + CountCriterion(a, size, i + 1);
}

// Сума елементів, що задовольняють критерій
int SumCriterion(const int* a, const int size, int i)
{
    if (i >= size)
        return 0;
    return (Criterion(a[i], i) ? a[i] : 0) + SumCriterion(a, size, i + 1);
}

// Заміна нулями елементів, що задовольняють критерій
void ZeroCriterion(int* a, const int size, int i)
{
    if (i >= size)
        return;
    if (Criterion(a[i], i))
        a[i] = 0;
    ZeroCriterion(a, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 25;
    const int Low = 5, High = 90;
    int a[n];

    Create(a, n, Low, High, 0);
    cout << "Initial array:" << endl;
    Print(a, n, 0);

    cout << "Amount: " << CountCriterion(a, n, 0) << endl;
    cout << "Sum: " << SumCriterion(a, n, 0) << endl;

    ZeroCriterion(a, n, 0);
    cout << "Modified array:" << endl;
    Print(a, n, 0);
    return 0;
}