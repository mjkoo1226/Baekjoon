shick = input()
gwalho = list(shick.split('-'))
answer = 0
for i in range(len(gwalho)):
    nums = list(map(int, gwalho[i].split('+')))
    if i == 0:
        answer += sum(nums)
    else:
        answer -= sum(nums)

print(answer)