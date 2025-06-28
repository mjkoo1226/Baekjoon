#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

int main(void){
    int n, len, k=0;
    int left = 0, right = 0;
    char arr[SIZE];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        left = 0, right = 0;
        k=0;
        scanf(" %s", arr);
        len = strlen(arr);
        for(int j=0; j<len; j++){
            if(arr[j] == '('){
                left++;
            }
            else if(arr[j] == ')'){
                right++;
            }
            if(left < right){
                k = -1;
            }
        }
        if(left == right && k == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}