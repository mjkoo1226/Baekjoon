#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Stacktype{
    char arr[SIZE];
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

void push(Stacktype *s, char value){
    s->arr[++(s->top)] = value;
}

char pop(Stacktype *s){
    return s->arr[(s->top)--];
}

char peek(Stacktype *s){
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
    char *s = malloc(sizeof(char) * SIZE);
    scanf("%s", s);
    infix_to_postfix(s);
    free(s);
    return 0;
}