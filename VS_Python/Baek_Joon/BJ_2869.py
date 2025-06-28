A, B, V = map(int, input().split())
if (V - A) % (A - B) == 0:
    day = 1 + (V - A) // (A - B)
else:
    day = 2 + (V - A) // (A - B)

print(day)