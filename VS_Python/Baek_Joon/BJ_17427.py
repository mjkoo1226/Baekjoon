n = int(input())

def g(N):
    total = 0
    i = 1
    
    while i <= N:
        q = N // i  
        j = N // q  
        
        total += q * (j * (j + 1) // 2 - (i - 1) * i // 2)
        
        i = j + 1
    
    return total

print(g(n))