import sys
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
nums.sort()

cnt = 0
for i in range(n):
    temp = nums[:i] + nums[i + 1:]
    left = 0
    right = len(temp) - 1
    while(left < right):
        if temp[left] + temp[right] == nums[i]:
            cnt += 1
            break
        elif temp[left] + temp[right] > nums[i]:
            right -= 1
        else:
            left += 1

print(cnt)