#include <stdio.h>
#include <stdlib.h>

static int compare (const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int binary_search(int a[], int n, int key){
	int start = 0;
	int last = n;
	int mid;

	while (last > start) {
		mid = (start + last) / 2;
		a[mid] > key ? last = mid : (start = mid + 1);	
	}
	int upper = last;					
	start = 0, last = n;
	while (last > start) {
		mid = (start + last) / 2;
		a[mid] >= key ? last = mid : (start = mid + 1);
	}
	return upper - last;
}

int main()
{
	int n, m;
	int* card;
	int val;

	scanf("%d", &n);

	card = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);

	qsort(card, n, sizeof(card[0]), compare);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &val);
		printf("%d ", binary_search(card, n, val));
	}
	free(card);
	return 0;
}