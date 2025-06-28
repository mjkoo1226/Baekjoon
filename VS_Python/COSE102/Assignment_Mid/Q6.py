# 2024320333 데이터과학과 구민준

a, b, c = map(int, input().split())

sum = [] # 합으로 가능한 숫자들의 리스트

for i in range(a+1): # 2점은 0~a번 득점 가능
    for j in range(b+1): # 3점은 0~b번 득점 가능
        for k in range(c+1): # 4점은 0~c번 득점 가능
            sum.append(2 * i + 3 * j + 4 * k) # 나온 합을 리스트에 추가

can = set(sum) # 집합으로 바꿔서 중복 제거
print(len(can)) # 정답 출력