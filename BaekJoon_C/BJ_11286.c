#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int abs(int n){
    if(n > 0) return n;
    else return -n;
}

typedef struct HEAP{
    int cnt;
    int index;
    int heapArray[MAX];
}HEAP;

HEAP* createHeap(void){
    HEAP *newheap = (HEAP*)malloc(sizeof(HEAP));
    if(!newheap) return NULL;

    newheap->cnt = 0;
    newheap->index = -1;
    for(int i = 0; i < MAX; i++){
        newheap->heapArray[i] = 0;
    }

    return newheap;
}

void reheapUp(HEAP *heap, int index){
    if (index == 0) return;

    int parent = (index - 1) / 2;

    if(abs(heap->heapArray[index]) < abs(heap->heapArray[parent])){
        int temp = heap->heapArray[parent];
        heap->heapArray[parent] = heap->heapArray[index];
        heap->heapArray[index] = temp;

        reheapUp(heap, parent);
    }
    else if(abs(heap->heapArray[index]) == abs(heap->heapArray[parent])){
        if(heap->heapArray[index] < heap->heapArray[parent]){
            int temp = heap->heapArray[parent];
            heap->heapArray[parent] = heap->heapArray[index];
            heap->heapArray[index] = temp;

            reheapUp(heap, parent);
    }
    }
}

void reheapDown(HEAP *heap, int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;

    if(left < heap->cnt){
        if(abs(heap->heapArray[left]) < abs(heap->heapArray[smallest]))
            smallest = left;
        else if (abs(heap->heapArray[left]) == abs(heap->heapArray[smallest]))
            if(heap->heapArray[left] < heap->heapArray[smallest])
                smallest = left;
    }

    if(right < heap->cnt){
        if(abs(heap->heapArray[right]) < abs(heap->heapArray[smallest]))
            smallest = right;
        else if (abs(heap->heapArray[right]) == abs(heap->heapArray[smallest]))
            if(heap->heapArray[right] < heap->heapArray[smallest])
                smallest = right;
    }

    if(smallest != index){
        int temp = heap->heapArray[smallest];
        heap->heapArray[smallest] = heap->heapArray[index];
        heap->heapArray[index] = temp;

        reheapDown(heap, smallest);
    }
}

void push(HEAP *heap, int data){
    heap->cnt++;
    heap->index++;
    heap->heapArray[heap->index] = data;

    reheapUp(heap, heap->index);
}

void pop(HEAP *heap, int *output){
    if(heap->cnt == 0){
        *output = 0;
        return;
    }
    
    *output = heap->heapArray[0];

    heap->heapArray[0] = heap->heapArray[heap->index];
    heap->heapArray[heap->index] = 0;

    heap->cnt--;
    heap->index--;

    if(heap->cnt > 0)
        reheapDown(heap, 0);
}

int main(void){
    int n;
    scanf("%d", &n);

    int data, temp = 0;

    HEAP *heap = createHeap();

    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        if (data == 0){
            pop(heap, &temp);
            printf("%d\n", temp);
        }
        else
            push(heap, data);
    }

    return 0;
}