x = int(input())
gun = 1
weishu = 1
while (gun // x * x != gun):
	gun = gun * 10 + 1
	weishu += 1
print(int(gun / x), weishu)
