# 2024 Fall COSE102 Midterm Exam
# 2024320333 구민준
# Q3

rooms = []
all_rooms = set()
empty = []

index = 0

max = 0
answer = ''

while 'END' not in rooms:
    rooms = list(input().split())
    all_rooms = set(list(all_rooms) + rooms)
    for room in rooms:
        empty.append((room, index))
    index += 1

for room in all_rooms:
    max_stric = 0
    stric = 0

    for i in range(index):
        if (room , i) in empty:
            stric += 1
            if stric > max_stric:
                max_stric = stric
        else:
            stric = 0
    
    if max_stric > max:
        answer = room
        max = max_stric

print(answer)