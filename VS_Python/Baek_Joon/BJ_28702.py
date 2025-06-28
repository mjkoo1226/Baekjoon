arr = []

arr.append(input())
arr.append(input())
arr.append(input())

answer = 0

for fuck in arr:
    if fuck != 'Fizz' and fuck != 'Buzz' and fuck != 'FizzBuzz':
        answer = int(fuck) - arr.index(fuck) + 3
        break

if answer % 15 == 0:
    print('FizzBuzz')
elif answer % 3 == 0:
    print('Fizz')
elif answer % 5 == 0:
    print('Buzz')
else:
    print(answer)