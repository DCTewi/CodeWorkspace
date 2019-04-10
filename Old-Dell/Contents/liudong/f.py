# 斐波那契数列前1000项
fab = [1, 1]
for i in range(2, 1000):
	fab.append(fab[i - 1] + fab[i - 2])

for i in range(0, 1000):
	print(fab[i], end=' ')
print()