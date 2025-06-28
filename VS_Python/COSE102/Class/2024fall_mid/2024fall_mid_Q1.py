# 2024 Fall COSE102 Midterm Exam
# 2024320333 구민준
# Q1

cant_use = input()
count = int(input())
answer = 1

while (count > 1):
    if cant_use not in str(answer):
        count -= 1
    
    answer += 1

print(answer)