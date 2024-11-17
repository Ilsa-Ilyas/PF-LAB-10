#include <stdio.h>
#include <string.h>

void count(const char *name, int i) {
    if (i >= 0) {
        printf("%c", name[i]);
        i--;
        count(name, i);
    } else {
        return;
    }
}

int main(void) {
    char name[100];
    printf("Enter a string: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    int length = strlen(name);
    printf("\n");
    count(name, length - 1);
    return 0;
}
