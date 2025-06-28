# 2022 Fall COSE102 Midterm Exam
# Q3

answer = list(input())
guess = list(input())

for i in range(len(guess)):
    if guess[i] == answer[i]:
        print("O", end="")
    elif guess[i] in answer:
        print("?", end="")
    else:
        print("X", end="")