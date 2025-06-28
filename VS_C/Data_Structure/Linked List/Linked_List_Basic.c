#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_List
{
    int count;
    Node* head;
    Node* tail;
}List;

typedef struct Node
{
    int value;
    Node* next;
}Node;

List* make_new_list()
{
    List* list = (List*)malloc(sizeof(List));
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}


void insert_head(List* list, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL) return;

    newnode->value = value;
    newnode->next = list->head;

    list->count += 1;
    list->head = newnode;
}

void insert_tail(List* list, List* prenode, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL) return;

    newnode->value = value;
    newnode->next = NULL;

    list->tail = newnode;
    list->count += 1;

    prenode->next = newnode;
}

void insert_mid(List* list, Node* prenode, int value)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(newnode == NULL) return;

    newnode->value = value;
    newnode->next = prenode->next;

    prenode->next = newnode;
    list->count += 1;
}


int main(void){
    List *list = make_new_list()
    int n;


    while(1){
        printf("넣을 값을 입력하세요 : ");
        scanf("%d", &n);
    }

}