n, m = map(int, input().split())

A = set(map(int, input().split()))
B = set(map(int, input().split()))

C = set(A ^ B)
print(len(C))
