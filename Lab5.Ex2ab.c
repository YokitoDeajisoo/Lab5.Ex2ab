#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int n, choice;
    int a[100]; // максимум 100 елементів

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1 — Ввести масив вручну\n");
        printf("2 — Згенерувати масив випадковими числами [-100; 100]\n");
        printf("3 — Вийти\n");
        printf("Ваш вибiр: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Введiть кiлькiсть елементiв масиву: ");
            scanf("%d", &n);

            if (n <= 0 || n > 100) {
                printf("Неприпустима довжина масиву.\n");
                continue;
            }

            if (choice == 1) {
                for (int i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }
            }
            else {
                srand((unsigned int)time(NULL));
                printf("Згенерований масив:\n");
                for (int i = 0; i < n; i++) {
                    a[i] = rand() % 201 - 100;
                    printf("a[%d] = %d\n", i, a[i]);
                }
            }

            // 1. Індекс максимального елемента
            int maxIndex = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] > a[maxIndex]) maxIndex = i;
            }
            printf("Iндекс максимального елемента: %d\n", maxIndex);

            // 2. Сума модулiв мiж першим i останнiм нулями
            int firstZero = -1, lastZero = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] == 0) {
                    if (firstZero == -1) firstZero = i;
                    lastZero = i;
                }
            }

            if (firstZero != -1 && lastZero != -1 && firstZero < lastZero) {
                int sum = 0;
                for (int i = firstZero + 1; i < lastZero; i++) {
                    if (a[i] < 0)
                        sum += -a[i];
                    else
                        sum += a[i];
                }
                printf("Сума модулiв елементiв мiж першим i останнiм нулями: %d\n", sum);
            }
            else {
                printf("Неможливо знайти два нулi або вони в неправильному порядку.\n");
            }
        }
        else if (choice == 3) {
            printf("Завершення програми.\n");
        }
        else {
            printf("Невiрний вибiр. Спробуйте ще раз.\n");
        }

    } while (choice != 3);

    return 0;
}

}
