import sys
input = sys.stdin.readline

def is_pel(word):
    if word == word[::-1]:
        return True
    else:
        return False

t = int(input())

# for _ in range(t):
#     n = int(input())
#     words = [''] * n
#     for i in range(n):
#         words[i] = input()
    
#     found = 0
#     for i in range(n):
#         for j in range(i+1, n):
#             if is_pel(words[i] + words[j]):
#                 found = 1
#                 print(words[i] + words[j])
#                 break
#             elif is_pel(words[j] + words[i]):
#                 found = 1
#                 print(words[j] + words[i])
#                 break
#         if found == 1:
#             break
    
#     if found == 0:
#         print("0")

for _ in range(t):
    n = int(input())
    words = [input().strip() for _ in range(n)]
    
    found = False
    for i in range(n):
        for j in range(n):
            if i != j:
                if is_pel(words[i] + words[j]):
                    print(words[i] + words[j])
                    found = True
                    break
        if found:
            break

    if not found:
        print("0")