# 2022 Summer COSE102 Midterm Exam
# Q3

min_cost = {}
nara = ''

while 1:
    ticket = list(input().split())

    if len(ticket) == 1:
        nara = ticket[0]
        break

    if ticket[0] not in min_cost or min_cost[ticket[0]] > ticket[1]:
        min_cost[ticket[0]] = ticket[1]

print(min_cost[nara])