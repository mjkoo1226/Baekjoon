S = list(input())

cnt1 = 0
cnt2 = 0
k = 0

for i in range(1, len(S)):
    if S[i] != S[i-1]:
        k += 1
        if k % 2 == 0:
            cnt1 += 1
        else :
            cnt2 += 1

print(max(cnt1, cnt2))

