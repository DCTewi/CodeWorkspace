import math

t = 1
n = int(input())
vis = [0] * (n + 5)
p = list(map(int, input().split()))

for i in range(n):
    j, cnt = i, 0
    while (vis[j] == 0):
        cnt += 1
        vis[j] = 1
        j = p[j] - 1
    
    if cnt != 0:
        t = t * cnt // math.gcd(t, cnt)

print(t % (10 ** n))
