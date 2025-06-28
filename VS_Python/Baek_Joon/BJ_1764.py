n, m = map(int, input().split())

no_listen = set(input() for i in range(n))
no_see = set(input() for i in range(m))

dbj = sorted(no_listen & no_see)
print(len(dbj), *dbj, sep='\n')