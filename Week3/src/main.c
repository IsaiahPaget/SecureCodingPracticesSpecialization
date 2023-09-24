#include <stdio.h>
#include <stdlib.h>
#include "fqlib.h"

void print_queue(QUEUE *qptr) {
    int i;
    for (i = 0; i < qptr->count; i++) {
        printf("%d ", qptr->que[(qptr->head + i) % qptr->size]);
    }
    printf("\n");
}

int main() {
    printf("hello, world\n");

    int queue_size = 10;
    
    QUEUE *my_queue = NULL;

    qmanage(&my_queue, 1, queue_size);

    int numberToPutOnQueue = 10;

    put_on_queue(my_queue, numberToPutOnQueue);

    print_queue(my_queue);

    take_off_queue(my_queue, &numberToPutOnQueue);

    print_queue(my_queue);

    qmanage(&my_queue, 0, 0);

    return 0;
}

/*  */