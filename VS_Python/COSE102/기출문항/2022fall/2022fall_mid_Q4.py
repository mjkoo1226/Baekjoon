# 2022 Fall COSE102 Midterm Exam
# Q4

x = list(map(int, input().split()))
y = list(map(int, input().split()))

n = len(x)
problem = 0

for i in range(n):
    for j in range(i+1, n):
        if (x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2 < 2500:
            problem += 1

if problem > 0:
    print("YES")
else:
    print("NO")