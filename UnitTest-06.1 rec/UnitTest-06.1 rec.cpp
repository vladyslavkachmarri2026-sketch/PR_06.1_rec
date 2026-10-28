#include "pch.h"                 //预компільований заголовок проєкту (має бути першим)
#include "CppUnitTest.h"         // бібліотека Microsoft для unit-тестів
#include "../PR_6.1 rec.cpp"   


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61rec
{
    TEST_CLASS(UnitTest61rec)
    {
    public:
        // Тест 1: перевіряє підрахунок кількості та суми
        TEST_METHOD(TestCountAndSum)
        {
            // Не підходять лише a[0]=3 та a[8]=15 (непарні з індексами, кратними 8)
            int a[10] = { 3, 4, 5, 6, 7, 9, 11, 13, 15, 8 };

            // Останній аргумент 0 це початковий індекс: рекурсія починає з першого елемента
            Assert::AreEqual(8, CountCriterion(a, 10, 0));   // 10 - 2 = 8
            Assert::AreEqual(63, SumCriterion(a, 10, 0));    // 4+5+6+7+9+11+13+8 = 63
        }

        // Тест 2: перевіряє заміну нулями
        TEST_METHOD(TestZero)
        {
            int a[10] = { 3, 4, 5, 6, 7, 9, 11, 13, 15, 8 };

            ZeroCriterion(a, 10, 0);     // рекурсивно замінюємо підходящі елементи нулями

            Assert::AreEqual(3, a[0]);   // не підійшов, тому залишився
            Assert::AreEqual(15, a[8]);  // не підійшов, тому залишився
            Assert::AreEqual(0, a[1]);   // підійшов, тому став нулем
        }
    };
}