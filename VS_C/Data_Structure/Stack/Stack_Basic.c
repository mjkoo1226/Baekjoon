#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Stacktype{
    int arr[SIZE]; //int형 데이터 SIZE개(여기선 100개)
    int top;
} Stacktype;

void init(Stacktype *s){
    s->top = -1; //배열은 index 0부터 시작
}

int is_empty(Stacktype *s){
    if(s->top == -1)
        return 1;
    else
        return 0;
}
//스택이 비어있는지 확인 : 비어있으면 1 아니면 0 반환

int is_full(Stacktype *s){
    if(s->top == SIZE - 1)
        return 1;
    else
        return 0;
}
//스택이 꽉차있는지 확인 : 꽉차있으면 1 아니면 0 반환

void push(Stacktype *s, int value){
    if(is_full(s) == 1){
        printf("Stack is full");
        exit(1);
    }
    printf("\nPushed! : %d\n", value);
    s->arr[++(s->top)] = value;
}
//push : 스택에 값 집어넣기

int pop(Stacktype *s){
    if(is_empty(s) == 1){
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--];
}
//pop : 스택에서 값 꺼내기

int main(void){
    Stacktype s;
    init(&s); //스택 초기화
    
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printf("\nPop : %d\n", pop(&s));
    printf("\nPop : %d\n", pop(&s));
    printf("\nPop : %d\n", pop(&s));

    printf("\nPop : %d\n", pop(&s));
    
    return 0;
}