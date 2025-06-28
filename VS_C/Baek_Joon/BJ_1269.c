#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b){
    if(*(int*)a > *(int*)b)
        return 1;
    else if(*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main(void){
    int n, m, sum = 0;
    scanf("%d %d", &n, &m);
    int A[n], B[m];

    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<m; i++)
        scanf("%d", &B[i]);
    qsort(A, n, sizeof(int), compare);
    qsort(B, m, sizeof(int), compare);

    int i=0, j=0;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            sum++;
            i++;
        } else if (A[i] > B[j]) {
            sum++;
            j++;
        } else {
            i++;
            j++;
        }
    }

    sum += n - i + m - j;
    printf("%d", sum);

    return 0;
}