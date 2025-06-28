import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    cmd = list(input())
    n = int(input())
    num = list(input().strip()[1:-1].split(","))

    for i in cmd:
        if i == 'R':
            num.reverse()
        elif i == 'D':
            if len(num) == 0:
                print("error")
                break
            else:
                num.remove(num[0])
    
    print('[' + ",".join(num) + ']')