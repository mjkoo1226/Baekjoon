import sys
import copy
input = sys.stdin.readline

dp = {}

def dfs(current:list, nums:list, depth:int, dp:dict):
    if depth == 0:
        if str(current) not in dp.keys():
            dp[str(current)] = 0
            print(*current)
        return
    
    for i in range(len(nums)):
        new = copy.deepcopy(current)
        new.append(nums[i])
        
        dfs(new, nums, depth - 1, dp)

n, m = map(int, input().split())

numlist = list(map(int, input().split()))
numlist.sort()

um = []

dfs(um, numlist, m, dp)