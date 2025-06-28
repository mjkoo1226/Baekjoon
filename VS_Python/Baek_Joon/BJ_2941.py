word = input()
arr = list(word)
len = len(arr)
count = 1
index = 1
while index < len :
    if(arr[index] == '='):
        if(arr[index - 1] == 'c' or arr[index - 1] == 's'):
            count -= 1
        if(arr[index - 1] == 'z'):
            count -= 1
            if index > 1 :
                if(arr[index - 2] == 'd') :
                    count -= 1
    if(arr[index] == '-'):
        if(arr[index - 1] == 'c' or arr[index - 1] == 'd'):
            count -= 1
    if(arr[index] == 'j'):
        if(arr[index - 1] == 'l' or arr[index - 1] == 'n'):
            count -= 1
    count += 1
    index += 1
print(count)
