#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_V 1001
#define INF 2147483647

typedef struct Node {
    int to;
    int weight;
    struct Node *next;
} Node;

Node *graph[MAX_V];
Node *rev_graph[MAX_V];

void add_edge(Node **g, int from, int to, int weight) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->to = to;
    newNode->weight = weight;
    newNode->next = g[from];
    g[from] = newNode;
}

// 최소 힙 구조체 및 함수 (우선순위 큐)
typedef struct {
    int v, dist;
} HeapNode;

HeapNode heap[MAX_V * 10];
int heap_size;

void heap_push(int v, int dist) {
    int i = ++heap_size;
    heap[i].v = v;
    heap[i].dist = dist;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        HeapNode tmp = heap[i]; heap[i] = heap[i/2]; heap[i/2] = tmp;
        i /= 2;
    }
}

HeapNode heap_pop() {
    HeapNode ret = heap[1];
    heap[1] = heap[heap_size--];
    int i = 1;
    while (1) {
        int l = i*2, r = i*2+1, min = i;
        if (l <= heap_size && heap[l].dist < heap[min].dist) min = l;
        if (r <= heap_size && heap[r].dist < heap[min].dist) min = r;
        if (min == i) break;
        HeapNode tmp = heap[i]; heap[i] = heap[min]; heap[min] = tmp;
        i = min;
    }
    return ret;
}

void dijkstra(Node **g, int n, int start, int *dist) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[start] = 0;
    heap_size = 0;
    heap_push(start, 0);
    while (heap_size) {
        HeapNode cur = heap_pop();
        int v = cur.v, d = cur.dist;
        if (dist[v] < d) continue;
        for (Node *p = g[v]; p; p = p->next) {
            if (dist[p->to] > d + p->weight) {
                dist[p->to] = d + p->weight;
                heap_push(p->to, dist[p->to]);
            }
        }
    }
}

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        add_edge(graph, a, b, t);
        add_edge(rev_graph, b, a, t); // 역방향 그래프
    }
    int toX[MAX_V], fromX[MAX_V];
    dijkstra(rev_graph, n, x, toX);   // 모든 마을 -> X (역방향)
    dijkstra(graph, n, x, fromX);     // X -> 모든 마을
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (toX[i] == INF || fromX[i] == INF) continue;
        if (max < toX[i] + fromX[i]) max = toX[i] + fromX[i];
    }
    printf("%d", max);
    return 0;
}
