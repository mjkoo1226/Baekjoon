# 2024320333 데이터과학과 구민준

name = list(input().split()) # 이름으로 구성된 리스트

cnt = 0 # 정답 0으로 초기화
for i in range(len(name)): # 사람수만큼 반복
    for j in range(len(name[i])) : # 이름 길이만큼 반복
        if name[i][j] == "고": # '고'가 들어가면 카운트 하고 다음사람으로
            cnt += 1
            break
        elif name[i][j] == "려": # '려'가 들어가면 카운트 하고 다음사람으로
            cnt += 1
            break
        elif name[i][j] == "대": # '대'가 들어가면 카운트 하고 다음사람으로
            cnt += 1
            break

print(cnt) # 정답 출력