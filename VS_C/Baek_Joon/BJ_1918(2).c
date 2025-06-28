#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
    char data;
    struct NODE *link;
} NODE;

typedef struct stack{
    int cnt;
    NODE *head;
} stack;

stack *makestack(void);
void DestroyStack(stack *pStack);
// 스택의 제작과 제거 함수

int push(stack *pStack, char value);
int pop(stack *pStack);
char stacktop(stack *pStack);
int stackcount(stack *pStack);
// 명령어 관련 함수들

int is_emptystack(stack *pStack);
int is_fullstack(void);
// 오버플로우 언더플로우 검사

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
    stack *s = makestack();

    for(int i=0; i<len; i++){
        ch = exp[i];
        switch(ch){
            case '+': case '-': case'*': case'/':
                while(!is_emptystack(s) && prec(ch) <= prec(stacktop(s))){
                    printf("%c", stacktop(s));
                    pop(s);
                }
                push(s, ch);
                break;
            case '(':
                push(s, ch);
                break;
            case ')':
                top_op = stacktop(s);
                pop(s);
                while(top_op != '('){
                    printf("%c", top_op);
                    top_op = stacktop(s);
                    pop(s);
                }
                break;
            default:
                printf("%c", ch);
                break;
        }
    }
    while(!is_emptystack(s)){
        printf("%c", stacktop(s));
        pop(s);
    }
    DestroyStack(s);
}

int main(void){
    char arr[101];
    scanf("%s", arr);

    infix_to_postfix(arr);
    return 0;
}

stack *makestack(void)
{
    stack *newstack = (stack*)malloc(sizeof(stack));
    if (newstack == NULL) return NULL;
    // 메모리 할당 실패시 NULL 리턴

    newstack->cnt = 0;
    newstack->head = NULL;

    return newstack;
}

int push(stack *pStack, char value)
{
    if (is_fullstack()) return 0;
    // 꽉차있으면 0 반환

    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    // if (newnode == NULL) return NULL;
    // 근데 여기선 is_fullstack 함수로 생성 가능한거 미리 확인함

    newnode->data = value;
    newnode->link = pStack->head;

    pStack->head = newnode;
    pStack->cnt++;

    return 1;
    // push 성공시 1 반환
}

int pop(stack *pStack)
{
    if (is_emptystack(pStack)) return 0;
    // 비어있으면 0 반환

    NODE *targetnode = pStack->head;

    pStack->head = targetnode->link;
    pStack->cnt--;
    free(targetnode);
    // pop 한 노드의 메모리 할당 헤제

    return 1;
    // pop 성공시 1 반환
}

char stacktop(stack *pStack)
{
    return pStack->head->data;
    // 스택의 맨 위 값을 반환
}

int is_emptystack(stack *pStack)
{
    if (pStack->cnt == 0) return 1;
    // 간단하게 스택 안의 노드 수가 0 이면 1 리턴
    else return 0;
}

int is_fullstack(void)
{
    NODE* test = (NODE*)malloc(sizeof(NODE));
    // 메모리 할당 시도해보고
    if (test == NULL) return 1;
    // 할당 실패시 메모리 부족으로 1 리턴
    else{
        free(test);
        return 0;
        // 스택이 꽉차있지 않으면 (메모리 할당이 가능하면) 0 리턴
    }
}

int stackcount(stack *pStack)
{
    return pStack->cnt;
}

void DestroyStack(stack *pStack)
{
    NODE *next = pStack->head;
    NODE *temp;

    while (next != NULL) {
        temp = next->link;
        free(next);
        next = temp;
    }
    // 노드들 모두 메모리 할당 해제

    free(pStack);
    // 스택도 메모리 할당 헤제
}