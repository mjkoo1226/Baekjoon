import math
gcd, lcd = map(int, input().split())

ab = lcd // gcd
answer_a = 0
answer_b = 0
min = ab + 2
i = 0

while i * i < ab:
    i += 1
    
    if ab % i != 0:
        continue
    
    a = i
    b = ab // i
    
    if math.gcd(a, b) != 1:
        continue
    
    if min > a + b:
        min = a + b
        answer_a = a * gcd
        answer_b = b * gcd

print(answer_a, answer_b)