# import sys
# input = sys.stdin.readline

# weight = {}
# value = {}
# dp = {}

# n, maxw = map(int, input().split())

# for i in range(n):
#     w, v = map(int, input().split())
#     weight[i] = w
#     value[i] = v

# ox = '0' * n
# dp[ox] = 0

# def adddp(key, index):
#     global maxw

#     if index >= len(key):
#         return
    
#     key2 = ''
    
#     if index == 0:
#         key2 = '1' + key[1:]
#     else:
#         key2 = key[:index] + '1' + key[index + 1:]
    

#     total_v = 0
#     total_w = 0

#     for i in range(len(key2)):
#         if key2[i] == '1':
#             total_v += value[i]
#             total_w += weight[i]
    
#     if total_w <= maxw:
#         dp[key2] = total_v
    
#     adddp(key, index + 1)
#     adddp(key2, index + 1)

# adddp(ox, 0)

# print(max(dp.values()))

import sys
input = sys.stdin.readline

n, maxw = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(n)]  # (weight, value) 리스트

dp = [0] * (maxw + 1)

for w, v in items:
    for weight in range(maxw, w - 1, -1):
        dp[weight] = max(dp[weight], dp[weight - w] + v)

print(max(dp))
