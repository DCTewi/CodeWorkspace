import math

p = 1000000007

def solve():
    b, c = map(int, input().split())
    delta = b ** 2 - 4 * c

    if delta != 0:
        print('-1 -1')
        return

    x = (b + int(math.sqrt(delta))) / 2
    y = c / x
    print(type(x))

def main():
    T = int(input())
    while T > 0:
        T -= 1
        solve()

if __name__ == '__main__':
    main()
