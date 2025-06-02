#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>

void runManualInput();
void runRandomGeneration();
void processArray(int* a, int n);

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int choice;

    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1 — Ввести масив вручну\n");
        printf("2 — Згенерувати масив випадковими числами [-100; 100]\n");
        printf("3 — Вийти\n");
        printf("Ваш вибiр: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            runManualInput();
            break;
        case 2:
            runRandomGeneration();
            break;
        case 3:
            printf("Завершення програми.\n");
            break;
        default:
            printf("Невiрний вибiр. Спробуйте ще раз.\n");
        }
    } while (choice != 3);

    return 0;
}

void runManualInput() {
    int n;
    printf("Введiть кiлькiсть елементiв масиву: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Неприпустима довжина масиву.\n");
        return;
    }

    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Помилка видiлення пам’ятi.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    processArray(a, n);
    free(a);
}

void runRandomGeneration() {
    int n;
    printf("Введiть кiлькiсть елементiв масиву: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Неприпустима довжина масиву.\n");
        return;
    }

    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Помилка видiлення пам’ятi.\n");
        return;
    }

    srand((unsigned int)time(NULL));
    printf("Згенерований масив:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 201 - 100;
        printf("a[%d] = %d\n", i, a[i]);
    }

    processArray(a, n);
    free(a);
}

void processArray(int* a, int n) {
    // 1. Індекс максимального елемента
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[maxIndex]) maxIndex = i;
    printf("Iндекс максимального елемента: %d\n", maxIndex);

    // 2. Сума модулів між першим і останнім нулями
    int firstZero = -1, lastZero = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (firstZero == -1) firstZero = i;
            lastZero = i;
        }
    }

    if (firstZero != -1 && lastZero != -1 && firstZero < lastZero) {
        int sum = 0;
        for (int i = firstZero + 1; i < lastZero; i++)
            sum += abs(a[i]);
        printf("Сума модулiв елементiв мiж першим i останнiм нулями: %d\n", sum);
    }
    else {
        printf("Неможливо знайти два нулi в масивi або вони у неправильному порядку.\n");
    }
}
