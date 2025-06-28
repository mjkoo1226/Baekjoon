#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

typedef struct Queue
{
    int front;
    int rear;
    int data[MAX];
}Queue;

void init(Queue *q)
{
    q->front = q->rear = 0;
}

int is_full(Queue *q)
{
    return ((q->rear + 1) % MAX == q->front);
}

int is_empty(Queue *q)
{
    return (q->front == q->rear);
}

void push(Queue *q, int item)
{
    if(is_full(q)){
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = item;
}

int pop(Queue *q)
{
    if(is_empty(q)){
        return -1;
    }
    q->front = (q->front + 1) % MAX;
    return q->data[(q->front)];
}

int size(Queue *q)
{
	if (q->front < q->rear)
		return q->rear - q->front;
	else
		return MAX - q->front + q->rear;
}

int main(){
    Queue q;
    int n, k, temp;

    init(&q);
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++){
        push(&q, i+1);
    }
    printf("<");
    for(int i=0; i<n; i++){
        for(int j=0; j<k-1; j++){
            temp = pop(&q);
            push(&q, temp);
        }
        if(size(&q) == 1){
            break;
        }
        temp = pop(&q);
        printf("%d, ", temp);
    }
    printf("%d>", pop(&q));

    return 0;
}