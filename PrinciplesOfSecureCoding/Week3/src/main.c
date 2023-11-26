#include <stdio.h>
#include <stdlib.h>
#include "fqlib.h"

void print_queue(QUEUE *qptr) {
    int i;
    for (i = 0; i < qptr->count; i++) {
        printf("%d ", qptr->que[(qptr->head + i) % qptr->size]);
    }
    printf("\n\n");
}


/*
    Instructions:

    Write a short program that uses the interface that the fragile implementation provides to write a program that creates queues, adds integers to those queues, and deletes numbers from those queues.

    Then find a sequence of calls to put_on_queue and take_off_queue that demonstrate that decreasing the size field in the header structure of a queue can cause elements previously added to the queue to become invisible. What value of size did you begin with, what value did you change it to, and what was the sequence of function calls you came up with?

    Next, write a second program to invoke the library functions to make one of the library functions crash. This can be due to an illegal memory reference or any other reason.
*/

int main() {
    printf("hello, world\n");

    int queue_size = 6;
    
    QUEUE *my_queue = NULL;

    qmanage(&my_queue, 1, queue_size);

    int numberToPutOnQueue[] = {10, 20, 30, 40 ,50, 60};

    for (int i = 0; i < sizeof(numberToPutOnQueue) / sizeof(int); i++) {
        put_on_queue(my_queue, numberToPutOnQueue[i]);
    }

    print_queue(my_queue);

    my_queue -> size = 3;

    take_off_queue(my_queue, &numberToPutOnQueue[3]);
    take_off_queue(my_queue, &numberToPutOnQueue[6]);

    print_queue(my_queue);

    qmanage(&my_queue, 0, 0);

    return 0;
}