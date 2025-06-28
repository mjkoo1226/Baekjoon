#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

typedef struct Stacktype{
    int arr[SIZE];
    int top;
} Stacktype;

void init(Stacktype *s){
    s->top = -1;
}

int is_empty(Stacktype *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}

int is_full(Stacktype *s){
    if(s->top == SIZE - 1)
        return 1;
    else
        return 0;
}

void push(Stacktype *s, int value){
    s->arr[++(s->top)] = value;
}

int pop(Stacktype *s){
    if(is_empty(s) == 1){
        return -1;
    }
    return s->arr[(s->top)--];
}

int seek(Stacktype *s){
    if(is_empty(s) == 1){
        return -1;
    }
    return s->arr[s->top];
}

int main(void){
    Stacktype s;
    int n, value;
    char cmd[10];
    init(&s);
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", cmd);
        if(strcmp(cmd, "push") == 0){
            scanf("%d", &value);
            push(&s, value);
        }
        else if(strcmp(cmd, "pop") == 0)
            printf("%d\n", pop(&s));
        else if(strcmp(cmd, "size") == 0)
            printf("%d\n", s.top + 1);
        else if(strcmp(cmd, "empty") == 0)
            printf("%d\n", is_empty(&s));
        else if(strcmp(cmd, "top") == 0)
            printf("%d\n", seek(&s));
    }
    return 0;
}