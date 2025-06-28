#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    char data;
    struct NODE *next;
}NODE;

typedef struct STACK
{
    int cnt;
    NODE *head;
}STACK;

STACK *makeStack(void){
    STACK *newstack = (STACK*)malloc(sizeof(STACK));
    if (!newstack) return NULL;

    newstack->cnt = 0;
    newstack->head = NULL;
    return newstack;
}

NODE *makeNode(char data){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if (!newNode) return NULL;

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void push(STACK *stack, char data){
    NODE *pNode = makeNode(data);
    if (!pNode) return;

    pNode->next = stack->head;
    stack->head = pNode;
    stack->cnt++;

    return;
}

char pop(STACK *stack){
    NODE *pNode = stack->head;
    char output;

    if (!pNode) return '\0';
    
    output = pNode->data;
    stack->head = pNode->next;
    stack->cnt--;
    free(pNode);
    
    return output;
}

void distroyStack(STACK *stack){
    NODE *pNode = stack->head;
    NODE *pNext = NULL;
    while (pNode != NULL){
        pNext = pNode->next;
        free(pNode);
        pNode = pNext;
    }
    free(stack);
}

int main(void){
    char str[1000001], bomb[41];
    scanf("%s", str);
    scanf("%s", bomb);

    int len = strlen(str);
    int blen = strlen(bomb);

    STACK *stack = makeStack();

    for (int i = 0; i < len; i++) {
        push(stack, str[i]);

        
        if (stack->cnt >= blen) {
            NODE *cur = stack->head;
            int match = 1;
            for (int j = blen - 1; j >= 0; j--) {
                if (cur == NULL || cur->data != bomb[j]) {
                    match = 0;
                    break;
                }
                cur = cur->next;
            }

           
            if (match) {
                for (int j = 0; j < blen; j++) {
                    pop(stack);
                }
            }
        }
    }
    
    char result[1000001];
    int idx = 0;
    while (stack->head) {
        result[idx++] = pop(stack);
    }
    distroyStack(stack);

    if (idx == 0) 
        printf("FRULA\n");
    else
        for (int i = idx - 1; i >= 0; i--)
            printf("%c", result[i]);

    return 0;
}
