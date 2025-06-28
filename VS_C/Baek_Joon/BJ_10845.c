#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

typedef struct Queue
{
    int front;
    int rear;
    int data[MAX];
}Queue;

void init(Queue *q)
{
    q->front = q->rear = -1;
}

int is_empty(Queue *q)
{
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int item)
{
    q->data[++(q->rear)] = item;
}

int dequeue(Queue *q)
{
    if(is_empty(q)){
        return -1;
    }
    return q->data[++(q->front)];
}

int seek_front(Queue *q)
{
    if(is_empty(q)){
        return -1;
    }
    return q->data[(q->front)+1];
}

int seek_rear(Queue *q)
{
    if(is_empty(q)){
        return -1;
    }
    return q->data[(q->rear)];
}

int main(){
    Queue q;
    int n, value;
    char cmd[10];

    init(&q);
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf(" %s", cmd);
        if(strcmp(cmd, "push") == 0){
            scanf("%d", &value);
            enqueue(&q, value);
        }
        else if(strcmp(cmd, "pop") == 0){
            printf("%d\n", dequeue(&q));
        }
        else if(strcmp(cmd, "size") == 0){
            printf("%d\n", q.rear - q.front);
        }
        else if(strcmp(cmd, "empty") == 0){
            printf("%d\n", is_empty(&q));
        }
        else if(strcmp(cmd, "front") == 0){
            printf("%d\n", seek_front(&q));
        }
        else if(strcmp(cmd, "back") == 0){
            printf("%d\n", seek_rear(&q));
        }
    }
    return 0;
}