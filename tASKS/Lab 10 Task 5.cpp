#include <stdio.h>

int count(int num[], int i, int sum) {
    if (i >= 0) {
        sum += num[i];
        return count(num, i - 1, sum);
    } else {
        return sum;
    }
}

int main(void) {
    int num[50], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int sum = 0;
    sum = count(num, n - 1, sum);
    printf("\nSum of elements: %d\n", sum);

    return 0;
}
