#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;

typedef struct QUEUE{
    int count;
    NODE *front;
    NODE *rear;
}QUEUE;

// make a new empty queue
QUEUE *makequeue(void);

// inserts data at the rear
// returns 0 if fail
// returns 1 if succ
int Enqueue(QUEUE *pQueue, int value);

// deletes data from the front
// returns 0 if fail
// returns 1 if succ
int Dequeue(QUEUE *pQueue);

// retrieves data from the front
int QFront(QUEUE *pQueue);

// retrieves data from the rear
int QRear(QUEUE *pQueue);

// returns 1 if empty
// returns 0 if not empty
int is_empty(QUEUE *pQueue);

// returns the number of nodes in queue
int QueueCount(QUEUE *pQueue);

// free the memory of pNode and destroy it
void destroyNode(NODE *pNode);

// free the memory of pQueue and destroy it
void destroyQueue(QUEUE *pQueue);

//////////////////////////////////////////////////////////////////////////////////////


int main(void){
    int value;
    char cmd[10];
    QUEUE *Queue = makequeue();
    
    printf("< commands >\n");
    printf("push\t:\tadd value to Queue\n");
    printf("pop\t:\tpop out front in Queue\n");
    printf("front\t:\tshow value on front\n");
    printf("rear\t:\tshow value on rear\n");
    printf("count\t:\tprint the number of nodes in Queue\n");
    printf("exit\t:\tend program\n");
    printf("\n");

    while(1){
        printf("> ");
        scanf(" %s", cmd);

        if (strcmp(cmd, "push") == 0){
            scanf("%d", &value);
            if (Enqueue(Queue, value))
                printf("pushed %d!\n\n", QRear(Queue));
            else
                printf("The Queue is FULL\n\n");
        }
        else if (strcmp(cmd, "pop") == 0){
            if (Dequeue(Queue))
                printf("popped!\n\n");
            else
                printf("The Queue is EMPTY\n\n");
        }
        else if (strcmp(cmd, "front") == 0){
            if (is_empty(Queue))
                printf("The stack is EMPTY\n\n");
            else
                printf("front : %d\n\n", QFront(Queue));
        }
        else if (strcmp(cmd, "rear") == 0){
            if (is_empty(Queue))
                printf("The stack is EMPTY\n\n");
            else
                printf("rear : %d\n\n", QRear(Queue));
        }
        else if (strcmp(cmd, "count") == 0){
            printf("number of nodes in Queue : %d\n\n", QueueCount(Queue));
        }
        else if (strcmp(cmd, "exit") == 0){
            destroyQueue(Queue);
            break;
        }
        else{
            printf("unknown command\n\n");
        }
    }
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////
// function declarations

QUEUE *makequeue(void)
{
    QUEUE* newqueue = (QUEUE*)malloc(sizeof(QUEUE));
    if (newqueue == NULL) return NULL;

    newqueue->count = 0;
    newqueue->front = NULL;
    newqueue->rear = NULL;

    return newqueue;
}

int Enqueue(QUEUE *pQueue, int value)
{
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) return 0;

    newnode->data = value;
    newnode->next = NULL;

    if (is_empty(pQueue)){
        pQueue->rear = newnode;
        pQueue->front = newnode;
        pQueue->count++;
    }
    else{
        pQueue->rear->next = newnode;
        pQueue->rear = newnode;
        pQueue->count++;
    }

    return 1;
}

int Dequeue(QUEUE *pQueue)
{
    if (is_empty(pQueue)) return 0;

    NODE *targetnode = pQueue->front;
    
    pQueue->front = targetnode->next;
    pQueue->count--;

    destroyNode(targetnode);
    
    return 1;
}

int QFront(QUEUE *pQueue)
{
    return pQueue->front->data;
}

int QRear(QUEUE *pQueue)
{
    return pQueue->rear->data;
}

int is_empty(QUEUE *pQueue)
{
    if (pQueue->count == 0) 
        return 1;
    else 
        return 0;
}

void destroyNode(NODE *pNode)
{
    free(pNode);
}

int QueueCount(QUEUE *pQueue)
{
    return pQueue->count;
}

void destroyQueue(QUEUE *pQueue)
{
    NODE *targetnode = pQueue->front;
    NODE *temp = NULL;

    while (targetnode != NULL){
        temp = targetnode->next;
        destroyNode(targetnode);
        targetnode = temp;
    }

    free(pQueue);
}