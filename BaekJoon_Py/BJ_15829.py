import sys
input = sys.stdin.readline

l = int(input())
word = list(map(ord, input()))

total = 0

for i in range(l) :
    total += (word[i] - 96) * (31 ** i)
    total = total % 1234567891

print(total)