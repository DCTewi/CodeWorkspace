x, y = 0, 0
  
def mul(a, b, mod):
    ans = 0
    while b > 0:
        if b % 2 == 1:
            ans = (ans + a % mod) % mod
        a = (a + a) % mod
        b >>= 1
    return ans
  
def exgcd(a, b):
    global x, y
    if b == 0:
        x, y = 1, 0
        return a
    d = exgcd(b, a % b)
    tmp, x = x, y
    y = tmp - a // b * y
    return d
  
def lcm(a, b):
    x, y = 0, 0
    g = exgcd(a, b)
    return a // g * b
  
n, k = 0, 0
a = []
b = []
  
def excrt():
    global x, y, a, b, n
    M, ans = b[0], a[0]
    for i in range(1, n):
        A, B = M, b[i]
        C = (a[i] - ans % B + B) % B
        x, y = 0, 0
        g = exgcd(A, B)
        if (C % g != 0):
            return -1
        x = mul(x, C // g, B)
        ans += x * M
        M = lcm(M, B)
        ans = (ans % M + M) % M
    return ans
  
def main():
    global n, k, a, b
    n, k = map(int, input().split())
    for i in range(0, n):
        bi, ai = map(int, input().split())
        a.append(ai)
        b.append(bi)
    ans = excrt()
  
    if ans == -1:
        print('he was definitely lying')
    elif ans > k:
        print('he was probably lying')
    else:
        print(ans)
  
if __name__ == '__main__':
    main()

