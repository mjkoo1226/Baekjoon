# 2024320333 데이터과학과 구민준

word = input()

alp = [0 for i in range(26)] # 알파벳별 등장 횟수를 나타내는 리스트
key = 0 # 키를 0으로 초기화

for i in range(len(word)) :
    if alp[ord(word[i]) - 97] == 0: # 각 알파벳에 해당하는 리스트가 0이면
        alp[ord(word[i]) - 97] += 1 # 해당 리스트에 1 추가
    else : # 만약 0이 아니면 이미 나온적이 있다는 뜻이므로
        key += 1 # 키에 1 추가 후 끝내기
        break

if key > 0 : # 키가 0보다 크면(1이 추가된적 있으면)
    print("NO") # 노 출력
else : # 키가 수정된적 없으면
    print("YES") #예스 출력