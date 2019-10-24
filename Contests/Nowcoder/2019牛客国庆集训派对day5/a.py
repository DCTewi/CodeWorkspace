import sys, math
while True:
    line = sys.stdin.readline()
    if not line:
        break
    a, b = (int(x) for x in line.split())
    print(a // b)
