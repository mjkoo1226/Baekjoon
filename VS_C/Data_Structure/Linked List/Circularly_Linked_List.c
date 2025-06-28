#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strdup, strcmp

typedef struct node
{
	int 		value;
	struct node	*link;
} NODE;

typedef struct link
{
    int count;
    NODE *head;
    NODE *tail;
}LINK;

LINK* makelist(void);
void distroylist(LINK *pLink);
static int compare(void *a, void *b);


int main(void){

}

LINK* makelist(void)
{
    LINK *newlink = (LINK*)malloc(sizeof(LINK));

    newlink->count = 0;
    newlink->head = NULL;
    newlink->tail = NULL;

    return newlink;
}

void distroylist(LINK *pList)
{
	NODE* targetNode = pList->head;

	while(targetNode != NULL){
		NODE *next = targetNode->link;
		free(targetNode);
		targetNode = next;
	}
    
	free(pList);
}

static int _search(LINK *pList, NODE **pPre, NODE **pLoc, int key)
{
	*pPre = NULL;
    *pLoc = pList->head;
    
    while (*pLoc != NULL && compare(&key, (*pLoc)->value) > 0) {
        *pPre = *pLoc;
        *pLoc = (*pLoc)->link;
    }

    if (*pLoc != NULL && compare(&key, (*pLoc)->value) == 0) {
        return 1;
    }

    return 0;
}

static int compare(const void *a, const void *b)
{
    int *p1 = (int*)a;
    int *p2 = (int*)b;

    if (*p1 > *p2) return 1;
    else if (*p1 < *p2) return -1;
    else return 0;
}



