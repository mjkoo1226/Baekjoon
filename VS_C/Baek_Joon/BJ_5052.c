#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct Trie
{
    struct Trie* child[MAX];
    int is_end;
}Trie;


Trie* make_trie() {
    Trie* newnode = (Trie*)malloc(sizeof(Trie));
    for (int i = 0; i < MAX; i++) {
        newnode->child[i] = NULL;
    }
    newnode->is_end = 0;
    return newnode;
}

int add_trie(Trie* root, char* num) {
    Trie* current = root;

    for (int i = 0; i < strlen(num); i++) {
        int index = num[i] - '0';

        if (current->child[index] == NULL) {
            current->child[index] = make_trie();
        }

        current = current->child[index];
        
        if (current->is_end == 1) {
            return 0;  
        }
        // 새로 들어온 단어가 접두사가 될수있는지
        
    }

    for (int i = 0; i < MAX; i++) {
        if (current->child[i] != NULL) {
            return 0; 
        }
    }
    // 기존에 입력된 단어중에 접두사가 있는지

    current->is_end = 1;
    return 1;  
}

void free_trie(Trie* node) {
    if (node == NULL) return;

    for (int i = 0; i < MAX; i++) {
        if (node->child[i] != NULL) {
            free_trie(node->child[i]);
        }
    }
    free(node);
}

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        Trie* root = make_trie();
        char num[11];
        int key = 1;

        for (int j = 0; j < n; j++) {
            scanf("%s", num);
            if (add_trie(root, num) == 0) {
                key = 0; 
            }
        }

        if (key == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        free_trie(root);
    }

    return 0;
}