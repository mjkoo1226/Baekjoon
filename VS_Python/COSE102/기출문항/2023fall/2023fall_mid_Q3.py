# 2023 Fall COSE102 Midterm Exam
# Q3

words = list(input().split())
maxlen = 0

for word1 in words:
    for word2 in words:
        if word1[len(word1) - 1] == word2[0]:
            temp = word1 + word2[1:len(word2)]
            if len(temp) > maxlen:
                maxlen = len(temp)
                print

print(maxlen)
