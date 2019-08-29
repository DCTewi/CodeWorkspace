import random

f = open("nogit.output.txt", mode="w")

def main():
    n = 5
    f.write(str(n) + "\n")
    for i in range(n):
        f.write(str(random.randint(1, 120) * 10) + " ")
    f.write("\n")

if __name__ == '__main__':
    for i in range(5):
        main()

