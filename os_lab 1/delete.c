//Write a program in C to delete an element at a desired position from an array.

#include <stdio.h>
#define SIZE 10


void delete(int array[], int pos) {

    if (pos < 0 || pos >= SIZE) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < SIZE - 1; i++) {
        array[i] = array[i + 1];
    }
    array[SIZE - 1] = 0;
}

void main() {
    int array[SIZE], pos;


    printf("Enter the elements of the array:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }


    printf("Enter the position of the element to be deleted (0 to %d): ", SIZE - 1);
    scanf("%d", &pos);


    delete(array, pos);


    printf("Array after deletion:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
