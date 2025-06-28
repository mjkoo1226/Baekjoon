# COSE214 assignment 1

# Q1 : Design an algorithm that finds the maximum and minimum values among n distinct integers
# n is a power of 2, i.e., n = 2 ^ k for some positive integer k

# Use divide and conquer to design the algorithm
# Make sure that the number of comparisons is exactly (3 / 2) * n - 2

k = int(input())
n = 2 ** k

arr = list(map(int, input().split()))

def find_min_max(arr, p, r):
    if r - p > 1:
        q = (p + r + 1) // 2
        max1, min1 = find_min_max(arr, p, q - 1)
        max2, min2 = find_min_max(arr, q, r)
        return max(max1, max2), min(min1, min2)
    else:
        if arr[p] > arr[r]:
            return arr[p], arr[r]
        else:
            return arr[r], arr[p]
    
maxx, minn = find_min_max(arr, 0, n - 1)
print(maxx, minn)

# Q2 : Write the result of the following code as a formula in terms of n
# n is a random positive integer

def X(n):
    r = 0
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            for k in range(j + 1):
                r += 1
    return 

# Answer : (n - 1) * n * (n + 1) / 3