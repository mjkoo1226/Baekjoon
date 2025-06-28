import math
n = int(input())

nums = [int(input()) for _ in range(n)]

chas = [0] * n
for i in range(n - 1):
    chas[i] = abs(nums[i] - nums[i + 1])
chas[n-1] = abs(nums[n-1] - nums[0])

gcd = chas[0]
for cha in chas:
   gcd = math.gcd(gcd, cha)

answer = []

for i in range(2, gcd + 1):
    if (gcd % i == 0):
        answer.append(i)
    
print(*answer)