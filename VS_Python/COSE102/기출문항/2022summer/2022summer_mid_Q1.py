# 2022 Summer COSE102 Midterm Exam
# Q1

cola = int(input())
empty = cola
drinked = cola

while empty >= 3:
    cola = empty // 3
    empty -= cola * 2
    drinked += cola

print(drinked)