#include <stdio.h>
#include <stdlib.h>
typedef struct Box {
    int* items;        
    int numItems;          
    struct Box** boxes;    
    int numBoxes;     
} Box;
int calculateTotalWeight(Box* box) {
    int totalWeight = 0;
    for (int i = 0; i < box->numItems; i++) {
        totalWeight += box->items[i];
    }
    for (int i = 0; i < box->numBoxes; i++) {
        totalWeight += calculateTotalWeight(box->boxes[i]);
    }
    return totalWeight;
}
Box* createBox(int* items, int numItems, Box** boxes, int numBoxes) {
    Box* box = (Box*)malloc(sizeof(Box));
    box->items = items;
    box->numItems = numItems;
    box->boxes = boxes;
    box->numBoxes = numBoxes;
    return box;
}
int main() {
    int items1[] = {7, 11};
    int items2[] = {18};
    int items3[] = {10, 23};
    Box* innerBox1 = createBox(items1, 2, NULL, 0);
    Box* innerBox2 = createBox(items2, 1, NULL, 0);
    Box* nestedBoxes1[] = {innerBox1, innerBox2};
    Box* mainBox = createBox(items3, 2, nestedBoxes1, 2);
    printf("Total weight of the main box: %d\n", calculateTotalWeight(mainBox));
    free(innerBox1);
    free(innerBox2);
    free(mainBox);
    return 0;
}
