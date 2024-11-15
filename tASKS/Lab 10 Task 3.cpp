#include <stdio.h>
#include <string.h>

struct Book {
    char title[50];
    char author[50];
    int ISBN;
    int pYear;
    int isAvailable;
};

void addBook(struct Book b[], int *count) {
    printf("Enter book title: ");
    scanf("%s", b[*count].title);
    getchar(); // Clear the newline character from the buffer

    printf("Enter book author: ");
    scanf("%s", b[*count].author);
    getchar(); // Clear the newline character from the buffer

    printf("Enter ISBN: ");
    scanf("%d", &b[*count].ISBN);

    printf("Enter book production year: ");
    scanf("%d", &b[*count].pYear); // Use %d for integer input

    printf("Enter book available (1 for available, 0 for not available): ");
    scanf("%d", &b[*count].isAvailable);

    (*count)++;
}

void status(struct Book b[], int count) {
    char searchBy[50];
    int checkout;

    printf("\nEnter book title: ");
    scanf("%s", searchBy);
    getchar(); // Clear the newline character from the buffer

    printf("Do you want to check out (0) or return the book (1): ");
    scanf("%d", &checkout);

    for (int i = 0; i < count; i++) {
        if (strcmp(searchBy, b[i].title) == 0) {
            if (checkout == 1) {
                b[i].isAvailable = 1;
                printf("Book returned successfully.\n");
            } else if (checkout == 0) {
                b[i].isAvailable = 0;
                printf("Book checked out successfully.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}

void searchBook(struct Book b[], int count) {
    char searchBy[50];

    printf("\nEnter book author or title: ");
    scanf("%s", searchBy);
    getchar(); // Clear the newline character from the buffer

    for (int i = 0; i < count; i++) {
        if (strcmp(searchBy, b[i].author) == 0 || strcmp(searchBy, b[i].title) == 0) {
            printf("Book found: %s by %s (ISBN: %d, Year: %d, Available: %s)\n", b[i].title, b[i].author, b[i].ISBN, b[i].pYear, b[i].isAvailable ? "Yes" : "No");
            return;
        }
    }
    printf("Book not found.\n");
}

int main(void) {
    struct Book b[100];
    int count = 0, choice;

    while (1) {
        printf("Press 1 to add a new book, 2 to search for book, 3 to return or issue a book, and 4 to quit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(b, &count);
                break;
            case 2:
                searchBook(b, count);
                break;
            case 3:
                status(b, count);
                break;
            case 4:
                return 0;
            default:
                printf("Wrong input. Please try again.\n");
        }
    }
    return 0;
}
