#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

int k=0;
char answer[SIZE * 2];

typedef struct Stacktype{
    int arr[SIZE]; //int형 데이터 SIZE개
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
        k = -1;
        return;
    }
    s->arr[++(s->top)] = value;
}
//push : 스택에 값 집어넣기

void pop(Stacktype *s){
    if(is_empty(s) == 1){
        k = -1;
        return;
    }
    s->arr[(s->top)--] = -1;
}
//pop : 스택에서 값 꺼내기

int seek(Stacktype* s){
	if (is_empty(s))
		return -1;
	else
		return s->arr[s->top];
}

int main(void){
    Stacktype s;
    int n, num[SIZE];
    int N=1, index=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &num[i]);
    }
    init(&s);
    for(int i=0; i<n; i++){
        if(seek(&s) < num[i]){
            while(seek(&s) < num[i]){
                push(&s, N++);
                answer[index++] = '+';
            }
        }
        else if(seek(&s) > num[i]){
            while(seek(&s) > num[i]){
                pop(&s);
                answer[index++] = '-';
            }
        }
        if (seek(&s) != num[i]){
			k = -1;
			break;
		}
		else{
			pop(&s);
			answer[index++] = '-';
		}
    }
    if(k == -1){
        printf("NO\n");
    }
    else{
        for(int i=0; i<index; i++){
            printf("%c\n", answer[i]);
        }
    }
    return 0;
}