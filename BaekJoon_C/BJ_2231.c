#include <stdio.h>

int main(){
    int n, temp, num;
    scanf("%d", &n);
    for (int i = 1; i < n; i++){
        temp = i;
        num = i;
        while(temp > 0){
            num += temp % 10;
            temp /= 10;
        }
        if (num == n){
            printf("%d", i);
            n = 0;
            break;
        }
    }
    if (n != 0){
        printf("%d", 0);
    }
    return 0;
}