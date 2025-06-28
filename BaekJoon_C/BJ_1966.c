#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0

typedef struct info {
	int num;
	int name;
} Info;

typedef Info* Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _lQueue
{
	int size;
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

void QueueInit(Queue * pq)
{
	pq->size = 0;
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	pq->size++;

}
Data Dequeue(Queue * pq)
{
	Node * delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	pq->size--;
	return retData;
}

Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}
void sort(int num, int* arr) {    //내림차순 버블정렬
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int saveNum = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = saveNum;
			}
		}
	}
}

int main(void)
{
	int testCase;
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		Queue q, q2;
		QueueInit(&q), QueueInit(&q2);
		int fileNum, fileCheck;
		scanf("%d%d", &fileNum, &fileCheck);
		int *orderArray = (int*)malloc(sizeof(int)*fileNum);
		for (int i = 0; i < fileNum; i++) {
			Info *info = (Info*)malloc(sizeof(Info));
			int order;
			scanf("%d", &order);
			orderArray[i] = order;
			info->name = i;
			info->num = order;
			Enqueue(&q, info);
		}
		sort(fileNum, orderArray);

		int countCheck = 0;
		while (q.size > 0) {                     
			if (QPeek(&q)->num != orderArray[countCheck]) {
				Info *info2 = QPeek(&q);
				Dequeue(&q);
				Enqueue(&q, info2);
			}
			else if (QPeek(&q)->num == orderArray[countCheck]) {
				if (QPeek(&q)->name == fileCheck) {
					break;
				}
				else if (q.size > 0) {
					Dequeue(&q);
				}
				countCheck++;
			}
		}
		printf("%d\n", countCheck + 1);
	}
}