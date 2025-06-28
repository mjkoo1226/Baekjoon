# 2023 Spring COSE102 Midterm Exam
# Q3

houses = []
i = 0

while(1):
    string = list(input().split())
    if 'END' in string:
        break
    
    houses.append(string)
    for j in range(1, 4):
        houses[i][j] = int(houses[i][j])
    i += 1

money = int(input())

for house in houses:
    while house[2] < money:
        house[2] += 1000
        house[3] -= 7
    
    while house[2] > money:
        house[2] -= 1000
        house[3] += 7

min = float('inf')
answer = ''

for house in houses:
    if house[1] > 33:
        continue
    else:
        if house[3] < min:
            min = house[3]
            answer = house[0]

print(answer)