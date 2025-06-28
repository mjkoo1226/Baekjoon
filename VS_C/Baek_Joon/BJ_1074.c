#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

typedef struct S
{
    int num[20];  
}S;

int main(void){
    S s;
    char cmd[10];
    int n, value;
    for(int i=0; i<20; i++){
        s.num[i] = 0;
    }

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", cmd);
        if(strcmp(cmd, "add") == 0){
            scanf("%d", &value);
            s.num[value-1] = 1;
        }
        else if(strcmp(cmd, "remove") == 0){
            scanf("%d", &value);
            s.num[value-1] = 0;
        }
        else if(strcmp(cmd, "check") == 0){
            scanf("%d", &value);
            printf("%d\n",s.num[value-1]);
        }
        else if(strcmp(cmd, "toggle") == 0){
            scanf("%d", &value);
            if(s.num[value-1] == 0)
                s.num[value-1] = 1;
            else if(s.num[value-1] == 1)
                s.num[value-1] = 0;
        }
        else if(strcmp(cmd, "all") == 0){
            for(int i=0; i<20; i++){
                s.num[i] = 1;
            }
        }
        else if(strcmp(cmd, "empty") == 0){
            for(int i=0; i<20; i++){
                s.num[i] = 0;
            }
        }
    }
    return 0;
}