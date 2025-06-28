n, m = map(int, input().split())
num = list(map(int, input().split()))

prefix_sum = [0] * (n + 1)
for i in range(n):
    prefix_sum[i+1] = prefix_sum[i] + num[i]

result = []

for _ in range(m):
    start, end = map(int, input().split())
    result.append(prefix_sum[end] - prefix_sum[start - 1])

print("\n".join(map(str, result)))

#누적 합 이용 문제