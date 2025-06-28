import sys
input = sys.stdin.readline

L, K, C = map(int, input().split())
can_cut = list(map(int, input().split()))
can_cut = sorted(set(can_cut + [0, L]))


def can_divide(max_length):
    count = 0
    last_cut = L
    for i in range(len(can_cut) - 1, 0, -1):
        if last_cut - can_cut[i-1] > max_length:
            count += 1
            last_cut = can_cut[i]
    return count <= C

def find_first_cut(max_length):
    last_cut = L
    for i in range(len(can_cut) - 1, 0, -1):
        if last_cut - can_cut[i-1] > max_length:
            last_cut = can_cut[i]
    return last_cut

left = 1 
right = L
best_length = L
first_cut = 0

while left <= right:
    mid = (left + right) // 2
    if can_divide(mid):
        best_length = mid
        first_cut = find_first_cut(mid)
        right = mid - 1
    else:
        left = mid + 1

print(best_length, first_cut)


