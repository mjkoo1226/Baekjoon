import sys
input = sys.stdin.readline     

t = int(input())

for _ in range(t):

    n, k = map(int, input().split())
    num = list(map(int, input().split()))
    num.sort()

    count = 0
    min = float('inf')

    bottom = 0
    top = n - 1

    while bottom < top:
        total = num[bottom] + num[top]
        chai = abs(total - k)

        if chai < min:
            min = chai
            count = 1  
        elif chai == min:
            count += 1 

        if total < k:
            bottom += 1
        elif total > k:
            top -= 1
        else:
            bottom += 1
            top -= 1

    print(count)
        


