n = int(input())

x = [0] * (n + 1)
x[1] = 1
for i in range(2, n):
    x[i] = (x[i - 1] + x[i - 2]) / 2

nums = list(str(x[n-1]))
print(nums)
