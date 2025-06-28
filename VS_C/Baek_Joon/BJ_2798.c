#include <stdio.h>

int main(void){
    int n, m, dev, min;
    int key1, key2, key3;
    int card[100];
    scanf("%d %d", &n, &m);
    min = m;
    for(int i=0; i<n; i++){
        scanf("%d", &card[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                dev = m - card[i] - card[j] - card[k];
                if(dev < min && dev >= 0){
                    key1 = i, key2 = j, key3 = k;
                    min= dev;
                }
                if(min == 0)
                    break;
            }
            if(min == 0)
                break;
        }
        if(min == 0)
            break;
    }
    printf("%d", card[key1] + card[key2] + card[key3]);
    return 0;
}