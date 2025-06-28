#include <stdio.h>
#include <stdlib.h>

typedef struct dot{
    int x;
    int y;
}dot;

static int compare(const void* a,const void* b){
    if((*(dot*)a).x > (*(dot*)b).x)
        return 1;
    else if((*(dot*)a).x < (*(dot*)b).x)
        return -1;
    else{
        if((*(dot*)a).y > (*(dot*)b).y)
            return 1;
        else if((*(dot*)a).y < (*(dot*)b).y)
            return -1;
        else
            return 0;
    }
}


int main(void){
    int n;
    scanf("%d", &n);
    dot a[n];
    for(int i=0; i<n; i++){
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    qsort(a, n, sizeof(dot), compare);
    for(int i=0; i<n; i++){
        printf("%d %d\n", a[i].x, a[i].y);
    }
    return 0;
}