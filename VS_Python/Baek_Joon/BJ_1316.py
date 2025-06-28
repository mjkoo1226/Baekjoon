n = int(input())
count = 0

for i in range(n) :
    count += 1
    word = input()
    arr = list(word)
    alp = [0 for i in range(26)]
    alp[ord(arr[0]) - 97] += 1
    for i in range(1, len(arr)) :
        if(arr[i] != arr[i-1]):
            alp[ord(arr[i]) - 97] += 1
    for i in range(26) :
        if(alp[i] > 1):
            count -= 1
            break
print(count)

