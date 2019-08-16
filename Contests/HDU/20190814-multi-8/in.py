import random
import math
import os

f = open('in.txt', mode='w+')
T = random.randint(1, 10)
f.write(str(T) + '\n')
for t in range(0, T):
    n = random.randint(1, 10)
    f.write(str(n) + '\n')
    for N in range(0, n):
        a = random.randint(1, 500)
        b = random.randint(1, 500)
        
        f.write(str(a) + ' ' + str(b) +'\n')


