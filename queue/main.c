#include <stdio.h>
#include <stdbool.h>

#include "implementation/circular_static_queue.h"
//#include "implementation/static_queue.h"

void printArr(int *arr, int size);

int main(void) {
    int size;
    printf("Size of the queue:");
    scanf("%d", &size);
    QueueI *queue = newCircularQueueI(size);
//    QueueI *queue = newQueueI(size);
    int choice;
    bool isFreed = false;
    do {
        printf("\nQueue Menu:\n\t1. Enqueue\n\t2. Dequeue\n\t0. Exit\n*Choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int val;
                printf("Val:");
                scanf("%d", &val);

                enqueueI(queue, val);
                break;
            }

            case 2: {
                int itemDequeued = dequeueI(queue);
                printf("Item Dequeued: %d\n", itemDequeued);
                break;
            }
            case 0:
                freeCircularQueueI(queue);
//                freeQueueI(queue);
                isFreed = true;
                printf("Exiting\n");
                break;
            default:
                printf("Invalid option");
                break;
        }
        if (!isFreed) {
            printf("*Queue is now: ");
            printArr(queue->arr, queue->size);
        }

    } while (choice != 0);

    return 0;
}

void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

