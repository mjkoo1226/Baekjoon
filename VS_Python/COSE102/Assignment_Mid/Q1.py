# 2024320333 데이터과학과 구민준

a = float(input())
b = float(input())

day = 0 # 몇일차인지

while a <= b : # a가 b보다 커지면 끝
    day += 1

    if day % 2 == 1 : # 홀수일차면 a에 10000원 추가
        a += 10000
    else : # 짝수일차면 a에 이자 7프로 추가
        a = a * (1.07)
    
    b = b * (1.02) # b에는 무조건 이자 2프로 추가

print(day)