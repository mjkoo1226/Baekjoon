import sys
input = sys.stdin.readline

n = int(input())
time = list(None for i in range(n))
end = list(None for i in range(n))

dic = dict()
for i in range(n) :
    time[i], end[i] = map(int, input().split())
    dic[end[i]] = time[i]

end.sort(reverse=True)

index = end[0]
for i in range(n) :
    if index > end[i] :
        index =  end[i] - dic[end[i]]
    else :
        index = index - dic[end[i]]

if index < 0 :
    index = -1

print(index)



