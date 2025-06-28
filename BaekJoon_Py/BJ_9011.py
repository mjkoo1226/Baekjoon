import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    R = list(map(int, input().split()))
    S = list(None for i in range(n))

    key = 1

    dic = list(range(1, n+1))
    for i in range(n-1, -1, -1) :
        if len(dic) - 1 < R[i] :
            key = -1
            break
        S[i] = dic[R[i]]
        dic.pop(R[i])
    
    if key == -1 :
        print("IMPOSSIBLE")
    else :
        print(*S, sep  = ' ')

