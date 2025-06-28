N, L = map(int, input().split())

for i in range(L, 101):
    gom = N - (i * (i + 1) // 2)
    if gom % i == 0:
        dori = gom // i
        if dori >= -1:
            print(*(i for i in range(dori + 1, dori + i + 1)))
            break
else:
    print(-1)