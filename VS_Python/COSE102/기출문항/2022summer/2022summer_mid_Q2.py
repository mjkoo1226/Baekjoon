# 2022 Summer COSE102 Midterm Exam
# Q2

menu_short = []
key = 0

while 1:
    menu = list(input().split())
    if 'END' in menu:
        break

    short = ''
    for word in menu:
        short += word[0]

    if short in menu_short:
        key = 1
    else:
        menu_short.append(short)

if key: print('YES')
else: print('NO')