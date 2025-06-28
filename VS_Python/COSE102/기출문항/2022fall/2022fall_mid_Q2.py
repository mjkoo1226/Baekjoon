# 2022 Fall COSE102 Midterm Exam
# Q2

dp = [2]
a = int(input())
b = int(input())
i = 0

def is_prime(n):
    if n in dp:
        return True
    elif n < dp[len(dp) - 1]:
        return False
    else:
        k = 1
        for i in dp:
            if n % i == 0:
                k = 0
        if k == 1:
            dp.append(n)
            return True
        else:
            return False
        
def include_ab(n):
    num = list(map(int, str(n)))
    if a in num and b in num:
        return True
    else:
        return False

while 1:
    i += 1
    if is_prime(i) == True and include_ab(i) == True:
        print(i)
        break