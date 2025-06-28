#include <stdio.h>
#include <stdlib.h>

int main(void){
    int t, n, fibo[41][2];
    scanf("%d", &t);

    fibo[0][0] = fibo[1][1] = 1;
    fibo[1][0] = fibo[0][1] = 0;

    for(int i=0; i<39; i++){
        fibo[i+2][0] = fibo[i+1][0] + fibo[i][0];
        fibo[i+2][1] = fibo[i+1][1] + fibo[i][1];
    }
    
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        printf("%d %d\n", fibo[n][0], fibo[n][1]);
    }

    return 0;
}