#include <stdio.h>

#include "implementation/static_queue.h"

int main(void) {
    QueueI *queue = newQueueI(5);
    enqueueI(queue, 10);
    enqueueI(queue, 20);
    enqueueI(queue, 30);
    enqueueI(queue, 40);
    enqueueI(queue, 50);
    enqueueI(queue, 60);

    for (int i = 0; i < 6; i++) {
        printf("%d\n", peekI(queue));
        dequeueI(queue);
    }
    freeQueueI(queue);
}