import sys
input = sys.stdin.readline

n = int(input())
a, b, c = map(int, input().split())

min_0, min_1, min_2 = a, b, c
max_0, max_1, max_2 = a, b, c

for _ in range(1, n):
    a, b, c = map(int, input().split())
    
    new_min_0 = a + min(min_0, min_1)
    new_min_1 = b + min(min_0, min_1, min_2)
    new_min_2 = c + min(min_1, min_2)
    
    new_max_0 = a + max(max_0, max_1)
    new_max_1 = b + max(max_0, max_1, max_2)
    new_max_2 = c + max(max_1, max_2)
    
    min_0, min_1, min_2 = new_min_0, new_min_1, new_min_2
    max_0, max_1, max_2 = new_max_0, new_max_1, new_max_2

min_value = min(min_0, min_1, min_2)
max_value = max(max_0, max_1, max_2)

print(max_value, min_value)