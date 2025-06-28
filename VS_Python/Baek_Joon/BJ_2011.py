import sys
input = sys.stdin.readline

def codenum(line: str):
    n = len(line)
    if line[0] == '0':  # 문자열이 0으로 시작하면 해독 불가
        return 0
    
    # dp 테이블 초기화
    dp = [0] * (n + 1)
    dp[0] = 1  # 빈 문자열을 해독하는 방법은 1가지
    dp[1] = 1  # 첫 문자는 해독 가능하므로 1로 설정

    # dp 계산
    for i in range(2, n + 1):
        # 한 자리 숫자 확인 (line[i-1])
        if 1 <= int(line[i-1:i]) <= 9:
            dp[i] += dp[i-1]
            dp[i] %= 1000000
        
        # 두 자리 숫자 확인 (line[i-2:i])
        if 10 <= int(line[i-2:i]) <= 26:
            dp[i] += dp[i-2]
            dp[i] %= 1000000

    return dp[n]

# 입력 처리
n = input().strip()
print(codenum(n))