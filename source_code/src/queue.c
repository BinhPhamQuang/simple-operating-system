#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t *q)
{
	return (q->size == 0);
}

void enqueue(struct queue_t *q, struct pcb_t *proc)
{
	/* TODO: put a new process to queue [q] */
	q->proc[q->size] = proc;
	q->size++;
	//end TODO
}

struct pcb_t *dequeue(struct queue_t *q)
{
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size != 0)
	{
		struct pcb_t *pcb_exit = q->proc[0];
		int index = 0;
		for (int i = 1; i < q->size; i++)
		{
			if (q->proc[i]->priority > pcb_exit->priority)
			{
				pcb_exit = q->proc[i];
				index = i;
			}
		}
		for (int i = index; i < q->size; i++)
		{
			q->proc[i] = q->proc[i + 1];
		}
		q->size--;
		return pcb_exit;
	}
	//endTODO
	return NULL;
}
