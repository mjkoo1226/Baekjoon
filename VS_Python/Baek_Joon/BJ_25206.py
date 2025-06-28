import dataclasses

class Subject:
    name:str = None
    time:float = None
    grade:str = None

timesum = 0
gradesum = 0

classs = list(Subject() for i in range(20))

for i in range(20):
    classs[i].name, time, classs[i].grade = input().split()
    classs[i].time = float(time)

    if(classs[i].grade == "A+") :
        grade = 4.5
    elif (classs[i].grade == "A0") :
        grade = 4.0
    elif (classs[i].grade == "B+") :
        grade = 3.5
    elif (classs[i].grade == "B0") :
        grade = 3.0
    elif (classs[i].grade == "C+") :
        grade = 2.5
    elif (classs[i].grade == "C0") :
        grade = 2.0
    elif (classs[i].grade == "D+") :
        grade = 1.5
    elif (classs[i].grade == "D0") :
        grade = 1.0
    elif (classs[i].grade == "F") :
        grade = 0.0

    if (classs[i].grade != "P") :
        timesum += classs[i].time
        gradesum += classs[i].time * grade

print(gradesum / timesum)
