#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100005
#define INF 2147483647


typedef struct HEAP{
    int cnt;
    int index;
    int heapArray[MAX_V];
    int data[MAX_V];
}HEAP;

HEAP* createHeap(void){
    HEAP *newheap = (HEAP*)malloc(sizeof(HEAP));
    if(!newheap) return NULL;

    newheap->cnt = 0;
    newheap->index = -1;
    for(int i = 0; i < MAX_V; i++){
        newheap->heapArray[i] = 0;
        newheap->data[i] = 0;
    }

    return newheap;
}

void reheapUp(HEAP *heap, int index){
    if (index == 0) return;

    int parent = (index - 1) / 2;

    if(heap->heapArray[parent] > heap->heapArray[index]){
        int temp = heap->heapArray[parent];
        heap->heapArray[parent] = heap->heapArray[index];
        heap->heapArray[index] = temp;

        temp = heap->data[parent];
        heap->data[parent] = heap->data[index];
        heap->data[index] = temp;

        reheapUp(heap, parent);
    }
}

void reheapDown(HEAP *heap, int index){
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int smallest = index;

    if(left < heap->cnt && heap->heapArray[left] < heap->heapArray[smallest])
        smallest = left;

    if(right < heap->cnt && heap->heapArray[right] < heap->heapArray[smallest])
        smallest = right;

    if(smallest != index){
        int temp = heap->heapArray[smallest];
        heap->heapArray[smallest] = heap->heapArray[index];
        heap->heapArray[index] = temp;

        temp = heap->data[smallest];
        heap->data[smallest] = heap->data[index];
        heap->data[index] = temp;

        reheapDown(heap, smallest);
    }
}

void push(HEAP *heap, int data, int priority){
    heap->cnt++;
    heap->index++;
    heap->heapArray[heap->index] = priority;
    heap->data[heap->index] = data;

    reheapUp(heap, heap->index);
}

void pop(HEAP *heap, int *output1, int *output2){    
    *output1 = heap->data[0];
    *output2 = heap->heapArray[0];

    heap->heapArray[0] = heap->heapArray[heap->index];
    heap->heapArray[heap->index] = 0;
    heap->data[0] = heap->data[heap->index];
    heap->data[heap->index] = 0;

    heap->cnt--;
    heap->index--;

    if(heap->cnt > 0)
        reheapDown(heap, 0);
}

typedef struct Node {
    int to;           
    int weight;     
    struct Node *next;
} Node;

Node *graph[MAX_V];

void add_edge(int from, int to, int weight) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->weight = weight;
    newNode->next = graph[from];
    graph[from] = newNode;
}

int main() {
    int v, e;
    int start;
    scanf("%d %d", &v, &e);
    scanf("%d", &start);

    for (int i = 0; i < e; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
    }

    HEAP *h = createHeap();

    int temp_v, temp_w;
    int distance[MAX_V];
    for(int i = 0; i < MAX_V; i++){
        distance[i] = INF;
    }
    distance[start] = 0;

    push(h, start, 0);

    while(h->cnt > 0){
        pop(h, &temp_v, &temp_w);

        if(temp_v < 1 || temp_v > v) continue;
        if(distance[temp_v] < temp_w) continue; // 이미 더 짧은 경로가 있으면 무시

        Node *current = graph[temp_v];
        while(current != NULL){
            if(current->to >= 1 && current->to <= v){
                int next_dist = temp_w + current->weight;
                if(distance[current->to] > next_dist){
                    distance[current->to] = next_dist;
                    push(h, current->to, next_dist);
                }
            }
            current = current->next;
        }
    }

    for(int i = 1; i <= v; i++){
        if(distance[i] == INF) printf("INF\n");
        else printf("%d\n", distance[i]);
    }

    return 0;
}
