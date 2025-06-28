# 2022 Fall COSE102 Midterm Exam
# Q1

choice = ""
angry = 0

while 1:
    choice = input()
    if choice == "END":
        break
    else:
        if angry > 0:
            print("D")
        else:
            print("C")
        
        if choice == "D":
            angry = 1
        elif choice == "C":
            angry = 0
