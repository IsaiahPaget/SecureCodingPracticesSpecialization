#include "saqlib.h"
#include <stdio.h>

int main(void)
{
	int variableToPutOnQueue = 10;

	QTICKET queueTicket = create_queue();
	QTICKET queueTicket2 = create_queue();

	put_on_queue(queueTicket, variableToPutOnQueue);
	put_on_queue(queueTicket2, variableToPutOnQueue);
	
	return 0;
}
