# 2022 Spring COSE102 Midterm Exam
# Q2

def TigerNumber(n:int):
    nums = list(map(int, str(n)))
    for i in nums:
        if n % i != 0:
            return False
    return True

# N = int(input())
# print(TigerNumber(N))