#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define NOTEMPTY -1
#define FOUND 2
#define NOTFOUND 3

typedef struct _Queue
{
	int x;
	struct _Queue *nextNode;
} Queue;

Queue * createQueue (Queue * queue, int x) // (a) requirment ok
{
	if (queue != NULL)
	{
		queue->x = x;
		queue->nextNode = NULL;
	}
	else 
	{
		queue = (Queue *)malloc(sizeof(Queue));
		queue->x = x;
		queue->nextNode = NULL;
	}

	return queue;
}
int isEmpty (Queue * queue) // (b) requirment
{
	if (queue == NULL) 
	{
		printf("Queue is empty\n");
		return EMPTY;
	}

	printf("Queue is not empty\n");
	return NOTEMPTY;
}

int isEmptyForPrintQueue (Queue * queue) // (b) requirment
{
	if (queue == NULL) 
		return EMPTY;
	return NOTEMPTY;
}

void insertAtTheEndOfQueue (Queue * queue, int x) // (c) requirment ok
{
	Queue * tmpQueue = queue;

	// search to the end of queue
	while (tmpQueue->nextNode != NULL)
		tmpQueue = tmpQueue->nextNode;

	//malloc & init next node.
	tmpQueue->nextNode = (Queue *)malloc(sizeof(Queue));
	// createQueue(tmpQueue->nextNode, tmpQueue->x + 1, tmpQueue->y + 1);
	createQueue(tmpQueue->nextNode, x);
}

int searchXY (Queue * queue, int x) // (d) ok
{
	Queue * tmpQueue = queue;

	while (tmpQueue != NULL)
	{
		if (tmpQueue->x == x)
		{
			printf("Found (%d)\n", x);
			return FOUND;
		}
		tmpQueue = tmpQueue->nextNode;
	}
	printf("(%d) not found.\n", x);
	return NOTFOUND;
}

Queue * deletePoint (Queue * queue, int x) // (e) ok
{
	Queue * tmpQueue = queue->nextNode;
	Queue * previousNode = queue;

	if (previousNode->x == x)
	{
		// printf("yes,x= %d, y= %d\n",previousNode->x,previousNode->y);
		previousNode = previousNode->nextNode;
		return previousNode;
	}

	while (tmpQueue != NULL)
	{
		//delete point
		if (tmpQueue->x == x)
		{	
			//check if Queue does have next node.
			if (tmpQueue->nextNode != NULL)
				previousNode->nextNode = tmpQueue->nextNode;
			else if (tmpQueue->nextNode == NULL)
				previousNode->nextNode = NULL;

			return queue;
		}
		tmpQueue = tmpQueue->nextNode;
		previousNode = previousNode->nextNode;
	}

	return queue;
}

void printOutQueue (Queue * queue) // (f) ok
{
	if (isEmptyForPrintQueue(queue) == NOTEMPTY)
	{
		Queue * tmpQueue = queue; 

		printf("This is your queue:\n");
		while (tmpQueue != NULL)
		{
			printf("(%d)", tmpQueue->x);
			if (tmpQueue->nextNode != NULL) 
				printf("->");
			tmpQueue = tmpQueue->nextNode;
		}
		printf("\n");
	}
	else
		printf("%s\n", "This queue is empty");
}

int countTheNumberOfPointsInQueue (Queue * queue) // (g) ok
{
	int counter = 0;
	Queue * tmpQueue = queue;

	while (tmpQueue != NULL)
	{
		counter += 1;
		tmpQueue = tmpQueue->nextNode;
	}

	printf("Count of queue is %d\n", counter);
	return counter;
}






int main ()
{
	//init queue & set next node to NULL
	Queue *queue;
	char i;
	int j, k;

	printf("Please choose function:\n");
	printf("(a) Create a queue of integer. ex: a 1, create a starting point (1).\n");
	printf("(b) Determine if a queue is empty.\n");
	printf("(c) Insert a integer at the end of a queue. ex: c 1, insert a point (1) at the end.\n");
	printf("(d) Search for a integer. ex: d 1, search for point (1).\n");
	printf("(e) Delete a integer. ex: e 1, delete point (1).\n");
	printf("(f) Print out a queue.\n");
	printf("(g) Count the number of points in a queue.\n");
	while (1)
	{
		printf("=> ");
		do {
			scanf("%c", &i);
		} while (i == 32 || i == 10);

		if (i == 'a')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);

			queue = createQueue(queue, j);
		}
		else if (i == 'b')
			isEmpty(queue);
		else if (i == 'c')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);

			insertAtTheEndOfQueue(queue, j);
		}
		else if (i == 'd')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);

			searchXY(queue, j);
		}
		else if (i == 'e')
		{
			do
			{
				scanf("%d", &j);
			} while (j == 32 || j == 10);

			queue = deletePoint(queue, j);
		}
		else if (i == 'f')
			printOutQueue(queue);
		else if (i == 'g')
			countTheNumberOfPointsInQueue(queue);
	}

	return 0;
}