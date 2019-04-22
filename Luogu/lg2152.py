def main():
    a = int(input())
    b = int(input())

    while ( b != 0 ):
        t = a % b
        a = b
        b = t

    print(a)

main()
