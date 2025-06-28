import sys
import re
input = sys.stdin.readline

t = int(input())
results = []

for _ in range(t):
    n = input().replace('\n', '')
    p = re.compile('(100+1+|01)+')
    m = p.fullmatch(n)
    if m: results.append("YES")
    else: results.append("NO")

for result in results:
    print(str(result))