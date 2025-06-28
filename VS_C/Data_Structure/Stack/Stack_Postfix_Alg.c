#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Stacktype{
    char arr[SIZE]; //int형 데이터 SIZE개(여기선 100개)
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
    s->arr[++(s->top)] = value;
}
//push : 스택에 값 집어넣기

char pop(Stacktype *s){
    if(is_empty(s) == 1){
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)--];
}
//pop : 스택에서 값 꺼내기

char peek(Stacktype *s){
    if(is_empty(s) == 1){
        printf("Stack is empty");
        exit(1);
    }
    return s->arr[(s->top)];
}

int prec(char op){
    switch(op){
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
    return -1;
}

void infix_to_postfix(char exp[]){
    char ch, top_op;
    int len = strlen(exp);
    Stacktype s;
    init(&s);

    for(int i=0; i<len; i++){
        ch = exp[i];
        switch(ch){
            case '+': case '-': case'*': case'/':
                while(!is_empty(&s) && prec(ch) <= prec(peek(&s))){
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while(top_op != '('){
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    while(!is_empty(&s)){
        printf("%c", pop(&s));
    }
}

int main(void){
    char *s = "(2+3)*4+9";
    printf("%s\n", s);
    infix_to_postfix(s);
    printf("\n");
    return 0;
}