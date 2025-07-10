import sys
import copy
input = sys.stdin.readline

def dfs(current:list, nums:list, depth:int):
    if depth == 0:
        print(*current)
        return
    
    for num in nums:
        new = copy.deepcopy(current)
        new.append(num)

        newnums = copy.deepcopy(nums)
        newnums.remove(num)
        
        dfs(new, newnums, depth - 1)

n, m = map(int, input().split())

numlist = list(map(int, input().split()))
numlist.sort()

um = []

dfs(um, numlist, m)