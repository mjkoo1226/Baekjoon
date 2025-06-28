n, m = map(int, input().split())
basket = list(0 for i in range(n))
for i in range(m) :
    a, b, value = map(int, input().split())
    for j in range(a-1, b) :
        basket[j] = value
for i in range(n) :
    print(basket[i], end=' ')