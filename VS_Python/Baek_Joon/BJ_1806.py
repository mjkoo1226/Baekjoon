n, s = map(int, input().split())
nums = list(map(int, input().split()))

left = 0
right = 0
current_sum = 0
min_length = n + 1

while right < n:
    current_sum += nums[right]
    right += 1
    
    while current_sum >= s:
        min_length = min(min_length, right - left)
        current_sum -= nums[left]
        left += 1

if min_length == n + 1:
    print(0)
else:
    print(min_length)