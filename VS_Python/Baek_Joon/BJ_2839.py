n = int(input())
big = n // 5
while 1 :
    if (n - big * 5) % 3 == 0 :
        break
    big -= 1
small = (n - big * 5) // 3 
if big < 0 or small < 0 :
    print("-1")
else :
    print(big + small)