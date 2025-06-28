import sys
input = sys.stdin.readline

n = int(input())
m = int(input())
s = input()

cnt = 0
i = 0
pattern = 0

while i < m - 1:
    if s[i] == 'I' and s[i+1] == 'O':
        j = i + 1
        while j+1 < m and s[j] == 'O' and s[j+1] == 'I':
            pattern += 1
            j += 2
        
        if pattern >= n:
            cnt += pattern - n + 1
        
        pattern = 0
        i = j
    else:
        i += 1

print(cnt)