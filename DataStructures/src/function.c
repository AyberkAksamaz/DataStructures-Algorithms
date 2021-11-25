#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "function.h"
#include "stack.h"

void bfs(int **adjMatrix, int numberOfVertex, int startVertex)
{
	LINKED_QUEUE q;
	q = linked_queue_init();
	int v;

	int dmap[numberOfVertex];

	for(int i=0; i<numberOfVertex; i++)
	{
		dmap[i] = 0;
	}

	linked_queue_enqueue(q, startVertex);  // enqueue s to q

	dmap[startVertex] = 1;   // mark s

	while(!linked_queue_is_empty(q))
	{
		v = linked_queue_dequeue(q);  // dequeue from q
		printf("%d  ", v);

		for(int j=0; j<numberOfVertex; j++)
		{
			if(adjMatrix[v][j] == 1)
			{
				if(dmap[j] !=1)
				{
					linked_queue_enqueue(q, (void *)j);
					dmap[j] = 1;
				}
			}
		}
	}

}
void dft(int **adjmatrix, int numberOfVertex, int startVertex)
{
	LINKED_STACK t;
	t = linked_stack_init();

	int v;
	int dmap[numberOfVertex];

	for(int i=0; i<numberOfVertex; i++)
	{
		dmap[i] = 0;
	}

	linked_stack_push(t, startVertex);
	dmap[startVertex] = 1;

	while(!linked_stack_is_empty(t))
	{
		v = linked_stack_pop(t);
		printf("%d  ", v);

		for(int j=0; j<numberOfVertex; j++)
		{
			if(adjmatrix[v][j] == 1)
			{
				if(dmap[j] != 1)
				{
					linked_stack_push(t, (void *)j);
					dmap[j] = 1;
				}
			}
		}
	}
}






