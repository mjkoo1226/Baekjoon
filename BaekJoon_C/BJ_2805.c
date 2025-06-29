#include <stdio.h>

#define MAX 1000000

long long tree[MAX];

int main() {
    int n;
    long long m;
    scanf("%d %lld", &n, &m);

    long long max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &tree[i]);
        if (tree[i] > max) max = tree[i];
    }

    long long low = 0, high = max;
    long long result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) {
                total += tree[i] - mid;
            }
        }

        if (total >= m) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", result);
    return 0;
}
