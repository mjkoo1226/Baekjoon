# 2022 Spring COSE102 Midterm Exam
# Q3

list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))

list1.sort()
list2.sort()

if list1 == list2:
    print("YES")
else:
    print("NO")