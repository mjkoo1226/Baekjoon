import sys
MAX = 1000000

measure = [0]*(MAX + 1)
total = [0]*(MAX + 1)

for i in range(1, (MAX+1)):
    for j in range(1, (MAX//i)+1):
        measure[i*j] += i 
    total[i] = total[i-1] + measure[i] 

t = int(input()) 

for _ in range(t):
    a = int(sys.stdin.readline())
    sys.stdout.write(str(total[a])+"\n")