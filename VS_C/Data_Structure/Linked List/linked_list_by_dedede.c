#include <stdio.h>
#include <stdlib.h> // malloc, realloc, free, qsort
#include <string.h> // strdup, strcmp, memmove

typedef struct Node
{
	int value;
	struct Node *next;
}Node;

typedef struct Linked_List
{
	int len;
	Node* head;
	Node* tail;
}List;

List* create_list();
void insert(List* list, Node* preNode, int value);
void insert(List* list, Node* preNode, int value);
void push(List *list, int value);
Node* pre_find(List *list, int value);
void printList(List *list);
void delete_list(List *list);

List* create_list()
{
	List* newList = (List*)malloc(sizeof(List)); 
	newList->len 	= 0;
	newList->head 	= NULL;
	newList->tail 	= NULL;
	return newList;
}

void insert(List* list, Node* preNode, int value)
{	
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL) return;
	
	list->len += 1;
	newNode->value = value;
	
	if(list->len == 1){
		list->head = newNode;
		newNode->next = NULL;
	}
	else if(preNode == NULL) push(list, value);
	else{
		newNode->next = preNode->next;
		preNode->next = newNode;
	}
	if(newNode->next == NULL) list->tail = newNode;
	return;
}

void erase(List *list, Node* preNode)
{
	Node* targetNode = preNode->next;
	if(targetNode == NULL) return;
	
	list->len -= 1;
	if(list->len == 0){
		list->head = NULL;
		list->tail = NULL;
	}
	else{
		preNode->next = targetNode->next;
		if(preNode->next == NULL) list->tail = preNode;
	}
	free(targetNode);
	printf("삭제했습니다\n");
	return;
}

void push(List *list, int value)
{
	printf("맨 뒤에 %d 를 push 했습니다.\n", value);
	insert(list, list->tail, value);
}

Node* pre_find(List *list, int value)
{
	Node *preNode;
	preNode = list->head;
	if(preNode == NULL) return NULL;
	
	while(preNode->next != NULL && preNode->next->value != value)
		preNode = preNode->next;
	
	return preNode;
}

void printList(List *list)
{
	Node *targetNode;
	targetNode = list->head;
	
	while(targetNode != NULL){
		printf("%d ", targetNode->value);
		targetNode = targetNode->next;
	}	
	printf("\n");
}

void delete_list(List *list)
{
	Node* targetNode = list->head;
	while(targetNode != NULL)
	{
		Node *next = targetNode->next;
		free(targetNode);
		targetNode = next;
	}
	free(list);
}

int main()
{
	List *list = create_list();
	push(list, 5);
	push(list, 3);
	push(list, 7);
	push(list, 9);
	push(list, 1);
	
	printList(list);
	erase(list, pre_find(list, 3));
	printList(list);
	insert(list, pre_find(list, 9), 100);
	printList(list);

	delete_list(list);
}