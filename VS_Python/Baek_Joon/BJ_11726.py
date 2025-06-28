def square(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    
    pb = list(0 for i in  range(n + 1))
    pb[1] = 1
    pb[2] = 2
    
    for i in range(3, n + 1):
        pb[i] = (pb[i - 1] + pb[i - 2]) % 10007

    return pb[n]

n = int(input())
print(square(n))