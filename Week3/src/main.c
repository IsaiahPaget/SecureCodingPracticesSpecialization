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