# 2024320333 데이터과학과 구민준

n = int(input())

sum = 1 # 약수들의 합
yaksu = [1] # 약수들의 배열

for i in range(2, n) : # 1은 이미 있으니 2부터
    if n % i == 0 : # n이 i로 나누어지면
        sum += i
        yaksu.append(i) # i는 n의 약수이므로 배열에 추가

if sum == n : # 약수들의 합과 자기 자신이 같으면 완전수
    print("YES")
else :
    print("NO")