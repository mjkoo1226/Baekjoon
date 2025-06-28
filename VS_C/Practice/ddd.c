#include <stdio.h>

int main(void){
    int i = 10;
    int *p = &i;

    printf("i = %d, p = %d\n", i, *p);

    (*p)++;

    printf("i = %d, p = %d\n", i, *p);

    *p++;

    printf("i = %d, p = %d\n", i, *p);

    return 0;
}
