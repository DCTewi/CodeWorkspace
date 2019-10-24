#lg1009

def exp(n):
	ans = 1
	for i in range(2, n + 1):
		ans *= i
	pass
	return ans
pass

n = int(input())
tot = 0
for i in range(1, n + 1):
        tot += exp(i)
pass
print(tot)
