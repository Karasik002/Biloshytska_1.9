#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int min_steps(int x, int y) {
    if (x == y) return 0;

    int distance = y - x;
    int steps = 0;
    int current_step = 0;

    while (distance > 0) {
        current_step++;
        distance -= current_step;
        steps++;
        if (distance <= 0) break;

        if (distance - current_step > 0) {
            distance -= current_step;
            steps++;
        }
    }

    return steps;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x, y;
    printf("Введіть значення x і y: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || y < 0 || x > y || y >= 2147483648) {
        printf("Неправильні вхідні дані. 0 <= x <= y < 2^31\n");
        return 1;
    }

    int result = min_steps(x, y);
    printf("Мінімальна кількість кроків: %d\n", result);

    return 0;
}
