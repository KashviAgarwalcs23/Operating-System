#include <stdio.h>
#include <stdlib.h>
#define PRODUCER_SIZE 5

int is_full(int *full) {
    return (*full >= PRODUCER_SIZE) ? 0 : 1;
}

void wait(int *mutex) {
    --*mutex;
}

void signal(int *mutex) {
    ++*mutex;
}

void producer(int item, int *full, int *empty, int *x, int *mutex) {
    wait(mutex);
    if (!is_full(full)) {
        printf("Buffer is full, producer cannot produce.\n");
    } else {
        ++*full;
        --*empty;
        (*x)++;
        printf("Producer has produced : Item %d : %d\n", *x, item);
    }
    signal(mutex);
}

void consumer(int *full, int *empty, int *x, int *mutex) {
    wait(mutex);
    if (*full == 0) {
        printf("Buffer is empty, consumer cannot consume.\n");
    } else {
        printf("Consumer has consumed : Item %d\n", *x);
        (*x)--;
        --*full;
        ++*empty;
    }
    signal(mutex);
}

int main() {
    int full = 0, empty = PRODUCER_SIZE, item, x = 0, mutex = 1;
    int choice;

    while (1) {
        printf("Press (1) for Producer and (2) for Consumer: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item for the producer to produce: ");
                scanf("%d", &item);
                producer(item, &full, &empty, &x, &mutex);
                break;
            case 2:
                consumer(&full, &empty, &x, &mutex);
                break;
            default:
                printf("Invalid choice, exiting.\n");
                exit(0);
        }
    }
    return 0;
}
