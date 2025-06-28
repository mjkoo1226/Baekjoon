#include<stdio.h>
 
int main() {
    int i = 0;
    switch (1+1){
        case 2:
            printf("%d\n", i);
        case 3:
            printf("2");
        default:
            printf("3");
    }
    return 0;
}