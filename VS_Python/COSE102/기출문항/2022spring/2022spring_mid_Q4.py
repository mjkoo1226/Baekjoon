# 2022 Spring COSE102 Midterm Exam
# Q4

line = {}

line['q'] = line['w'] = line['e'] = line['r'] = line['t'] = 1
line['y'] = line['u'] = line['i'] = line['o'] = line['p'] = 1

line['a'] = line['s'] = line['d'] = line['f'] = line['g'] = 2
line['h'] = line['j'] = line['k'] = line['l'] = 2

line['z'] = line['x'] = line['c'] = line['v'] = 3
line['b'] = line['n'] = line['m'] = 3

line[' '] = 4

alph = list(input())
total = 0

for i in range(1, len(alph)):
    total += abs(line[alph[i]] - line[alph[i - 1]])

print(total)