import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dic = {}

for i in range(n) :
    name, temp = input().split()
    num = int(temp)
    dic[name] = num
    dic[num] = name

for i in range(m) :
    cmd = input().rstrip()
    if cmd.isdigit():
        print(dic[int(cmd)])
    else :
        print(dic[cmd])
        


