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
    int v, e, ans = 0;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
        add_edge(b, a, w);
    }

    HEAP *h = createHeap();

    int temp_v, temp_w;
    char visited[MAX_V];
    for(int i = 0; i < MAX_V; i++){
        visited[i] = 0;
    }

    push(h, 1, 0);

    int visited_cnt = 0;
    while(h->cnt > 0){
        pop(h, &temp_v, &temp_w);

        // 정점 번호가 1~v 범위인지 체크
        if(temp_v < 1 || temp_v > v) continue;
        if(visited[temp_v] > 0) continue;

        visited[temp_v] = 1;
        ans += temp_w;
        visited_cnt++;
        if(visited_cnt == v) break; // 모든 정점 방문 시 종료

        Node *current = graph[temp_v];

        while(current != NULL){
            if(!visited[current->to] && current->to >= 1 && current->to <= v) // push 전에 범위 체크
                push(h, current->to, current->weight);
            current = current->next;
        }
    }

    printf("%d\n", ans);

    return 0;
}
