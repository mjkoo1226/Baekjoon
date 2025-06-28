# 2024320333 데이터과학과 구민준

n = list(list(map(int, input().split())) for i in range(3))

check = 0
checkset = set(n[0] + n[1] + n[2])
if checkset == {1, 2, 3, 4, 5, 6, 7, 8, 9}:
    check = 1 # 1에서 9까지 한번씩 포함하는지 검사

sum1 = [0, 0, 0] # 가로 합들의 리스트
sum2 = [0, 0, 0] # 세로 합들의 리스트
sum3 = [0, 0] # 대각선 합들의 리스트

for i in range(3) :
    for j in range(3) :
        sum1[i] += n[i][j] # 가로 합 리스트 채우기
for i in range(3) :
    for j in range(3) :
        sum2[i] += n[j][i] # 새로 합 리스트 채우기
sum3[0] = n[0][0] + n[1][1] + n[2][2] # 대각선 오른쪽아래 방향
sum3[1] = n[2][0] + n[1][1] + n[0][2] # 대각선 오른쪽위 방향

all_sum = set(sum1 + sum2 + sum3) # 가능한 모든 합들의 집합

if len(all_sum) == 1 : # 집합의 원소가 1개이면 합이 모두 같다는거
    if check == 1 : 
        print("YES") # 다 통과되면 예스 출력
    else :
        print("NO") # 잘못된게 있으면 노 출력
else :
    print("NO") # 합이 다른 줄이 존재하므로 노 출력



# key = 0 설정해놓고 합이 무조건 15만 가능함을 이용해서 15가 아닌 다른 수 나오면 key를 바꾸고 마지막에 검사는 방식도 가능할듯
# 1에서 9까지 중복없이 모두 나오는지 판단하는게 필요한건지는 잘 모르겠으나 일단 추가함