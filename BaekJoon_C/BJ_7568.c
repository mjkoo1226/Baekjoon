#include <stdio.h>
#include <stdlib.h>

typedef struct people{
    int cm;
    int kg;
    int num;
}people;

const int compare(const void* a, const void* b){
    if((*(people*)a).cm > (*(people*)b).cm)
        return 1;
    else if((*(people*)a).cm < (*(people*)b).cm)
        return -1;
    else{
        if((*(people*)a).kg > (*(people*)b).kg)
            return 1;
        else if((*(people*)a).kg < (*(people*)b).kg)
            return -1;
        else
            return 0;
    }
}

int main(void){
    people p[50];
    int n, grade;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &p[i].kg, &p[i].cm);
    qsort(p, n, sizeof(people), compare);

    for(int i=0; i<n-1; i++){
        grade = n - i;
        if(p[i].kg < p[i+1].kg || p[i].cm < p[i+1].cm){
            grade--;
        }
        p[i].num = grade;
    }
    for(int i=0; i<n; i++){
        printf("%d ", p[i].num);
    }
    return 0;
}