import sys
import copy
input = sys.stdin.readline

def dfs(current:list, nums:list, depth:int):
    if depth == 0:
        print(*current)
        return
    
    for i in range(len(nums)):
        new = copy.deepcopy(current)
        new.append(nums[i])

        newnums = copy.deepcopy(nums)
        newnums = newnums[i::]
        
        dfs(new, newnums, depth - 1)

n, m = map(int, input().split())

numlist = list((i + 1) for i in range(n))

um = []

dfs(um, numlist, m)