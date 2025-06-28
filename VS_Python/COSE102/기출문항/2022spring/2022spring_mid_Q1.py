# 2022 Spring COSE102 Midterm Exam
# Q1

gagu = list(map(int, input().split()))
gagu.sort(reverse=True)

average = (sum(gagu) - gagu[0]) / (len(gagu) - 1)

if gagu[0] > average * 1.5 :
    print(gagu[0])
else :
    print("Not Found")