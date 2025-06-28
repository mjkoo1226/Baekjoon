# 2024 Fall COSE102 Midterm Exam
# 2024320333 구민준
# Q2

import math

num = input()
count = 0
dp = []

for i in range(2, len(num)):
    for j in range(len(num) - i + 1):
        if num[j : j + i] in dp:
            continue 
        
        if math.sqrt(int(num[j : j + i])) == int(math.sqrt(int(num[j : j + i]))):
            dp.append(num[j : j + i])
            count += 1

print(count)