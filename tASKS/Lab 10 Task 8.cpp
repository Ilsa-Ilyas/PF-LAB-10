#include <stdio.h>
void count(int num[], int i, int n) {
    if (i >= 0) {
        printf("\nElement %d is %d", i + 1, num[i]);
        i--;
        count(num, i, n);
    } else {
        return;
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
    count(num, n - 1, n);
    return 0;
}
