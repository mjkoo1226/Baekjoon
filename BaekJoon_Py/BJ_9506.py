n = 0
while n != -1 :
    n = int(input())
    if n == -1 :
        break
    sum = 1
    yaksu = [1]
    for i in range(2, n // 2 + 2) :
        if n % i == 0 :
            sum += i
            yaksu.append(i)
    if sum == n :
        print(n, "= ", end = '')
        print(*yaksu, sep = " + ")
    else :
        print(n, "is NOT perfect.")