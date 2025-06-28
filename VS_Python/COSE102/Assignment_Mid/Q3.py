# 2024320333 데이터과학과 구민준

pointing = list(input().split()) # 사람 이름으로 구성된 맴버 리스트
pointed = list(input().split()) # 사람 이름으로 구성된 지목 리스트
start = input()
N = int(input())

arrow = dict() # 누가 누굴 가르키는지 나타내는 딕셔너리
end:str = None # 벌칙 받는 사람

for i in range(len(pointing)) :
    arrow[pointing[i]] = pointed[i] # pointing[i] -> pointed[i]

end = start # 0번 시행 상태에서는 첫 번째 참가자로 시작
for i in range(N) :
    end = arrow[end] # 지목한 사람에서 지목 당한 사람 변경

print(end)