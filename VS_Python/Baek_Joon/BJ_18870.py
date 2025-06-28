n = int(input())
dot = list(map(int, input().split()))
dot2 = sorted(set(dot))

index_map = {value: idx for idx, value in enumerate(dot2)}

for value in dot:
    print(index_map[value], end=" ")

