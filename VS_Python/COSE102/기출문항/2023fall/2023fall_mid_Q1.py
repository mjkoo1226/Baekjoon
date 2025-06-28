# 2023 Fall COSE102 Midterm Exam
# Q1

win = {}
winner = ''

while 1:
    A, B = input().split()

    if A in win:
        win[A] += 1
    else:
        win[A] = 1
    
    if win[A] == 3:
        winner = A
        break

print(winner)
