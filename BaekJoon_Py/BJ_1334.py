num = list(map(int, list(str(int(input()) + 1))))
jarisu = len(num)

head = 0
rear = len(num) - 1
key = 0

while (head < rear):
    if num[head] < num[rear]:
        key = 1
        
    num[rear] = num[head]
    head += 1
    rear -= 1
    
if(key == 1 and head == rear):
    num[head] += 1
    if num[head] > 9:
        num[head] = 0
        head -= 1
        rear += 1
    else:
        key = 0
else:
    head -= 1
    rear += 1

while (key == 1 and head >= 0 and rear < jarisu):
    num[head] += 1
    num[rear] += 1
    if num[head] > 9:
        num[head] = 0
        num[rear] = 0
        head -= 1
        rear += 1
    else:
        key = 0

if set(num) == {0}:
    num[0] = 1
    num.append(1)

print(''.join(map(str, num)))