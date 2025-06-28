n = int(input())
count = 0
k = 1
while count < n :
    count += k
    k += 1
bj = count - n + 1
bm = k - bj
if k % 2 == 0 :
    print(bj, bm, sep='/')
else :
    print(bm, bj, sep='/')