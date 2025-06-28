# 2023 Spring COSE102 Midterm Exam
# Q2

words = list(input())
elements = list(map(list, input().split()))

elements.sort(key=lambda x: -len(x))
result = []
i = 0

while i < len(words):
        matched = False

        for element in elements:
            if words[i:i+len(element)] == element:
                result.append(f'<{element}>')
                i += len(element)
                matched = True
                break
            
        if not matched:
            result.append(words[i])
            i += 1

print(''.join(result))
            


