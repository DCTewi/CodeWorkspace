T = int(input())

def check( n ):
    if n < 2:
        return False
    if n == 2:
        return True
    for i in range(2, n // 2 + 1):
        if (n % i) == 0:
            return False
    return True

def main():
    n, k = map(int, input().split())
    m = n // k

    ans = 1
    for i in range(2, m + 1):
        if (check(i) == True):
            ans *= i

    print(ans * k)

for i in range(T):
    main()