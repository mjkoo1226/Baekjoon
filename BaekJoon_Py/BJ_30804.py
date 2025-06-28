import sys
input = sys.stdin.readline

n = int(input())
fruit = list(map(int, input().split()))

def maxfinder(arr):
    left = 0
    fruit_count = {}
    max_length = 0

    for right in range(len(arr)):
        if arr[right] in fruit_count:
            fruit_count[arr[right]] += 1
        else:
            fruit_count[arr[right]] = 1

        while len(fruit_count) > 2:
            fruit_count[arr[left]] -= 1
            if fruit_count[arr[left]] == 0:
                del fruit_count[arr[left]]
            left += 1

        max_length = max(max_length, right - left + 1)

    return max_length


print(maxfinder(fruit))