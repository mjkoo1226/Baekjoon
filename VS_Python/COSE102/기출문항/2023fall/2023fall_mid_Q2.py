# 2023 Fall COSE102 Midterm Exam
# Q2

x = input()
k = int(input())

## 고능한 풀이
SosuPart = ''

for i in range(len(x)):
    if x[i] == '.':
        SosuPart = x[i + 1:len(x)]
        break

int_sosu = int(SosuPart)
tenten = 10 ** len(SosuPart)

if tenten % int_sosu == 0:
    key = tenten // int_sosu
else:
    key = tenten

## 저능한 풀이
# x = float(x)
# key = 1

# while 1:
#     t = x * key
#     if t == int(t):
#         break
#     else:
#         key += 1

print(key * k)