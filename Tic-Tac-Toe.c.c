#include <stdio.h>

int main() {
    int i = 1;
    float num, sum = 0;

    while (i <= 10) {
        printf("Enter number %d: ", i);
        scanf("%f", &num);
        sum += num;   // add to sum
        i++;
    }

    float avg = sum / 10.0;

    printf("Average = %.2f\n", avg);

    return 0;
}
