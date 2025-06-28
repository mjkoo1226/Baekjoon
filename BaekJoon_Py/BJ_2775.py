t = int(input())

for _ in range(t):
    k = int(input())
    n = int(input())

    total = 0
    saram = list(list(0 for j in range(n)) for i in range(k+1))

    for i in range(n):
        saram[0][i] = i + 1
    total += sum(saram[0])

    for i in range(1, k+1):
        for j in range(n):
            for p in range(j+1):
                saram[i][j] += saram[i - 1][p]
        total += sum(saram[i])
    
    print(saram[k][n-1])