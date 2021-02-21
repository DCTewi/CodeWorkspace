#coding=utf-8

import os
import json
from os.path import sameopenfile

showCount = 4

def update():
    with open("songlist.json", encoding="utf-8") as f:
        songlist = json.loads(f.read())

    result = ""
    if len(songlist) == 0:
        result = "当前队列为空"
    else:
        result = "【正在唱】\n{}\n".format(songlist[0])
        if len(songlist) > 1:
            result += "【队列中】\n{}".format("\n".join(songlist[1:showCount + 1]))
    
    with open("output.txt", mode="w+", encoding="utf-8") as f:
        f.write(result)


def add(s : str):
    with open("songlist.json", encoding="utf-8") as f:
        songlist = json.loads(f.read())

    songlist.append(s)

    with open("songlist.json", mode="w+", encoding="utf-8") as f:
        f.write(json.dumps(songlist).encode('latin-1').decode('unicode_escape'))

    update()

def next():
    with open("songlist.json", encoding="utf-8") as f:
        songlist = json.loads(f.read())

    if len(songlist) > 0:
        with open("song.txt", mode="a", encoding="utf-8") as f:
            f.write("{}\n".format(songlist[0]))
        songlist = songlist[1:]
    
    with open("songlist.json", mode="w+", encoding="utf-8") as f:
        f.write(json.dumps(songlist).encode('latin-1').decode('unicode_escape'))
    
    update()

def main():
    if not os.path.exists("songlist.json"):
        with open("songlist.json", mode="w+", encoding="utf-8") as f:
            f.write("[]")
    update()

    while True:
        op = input("|>")
        if op == "add":
            content = input("|内容> ")
            add(content)
        elif op == "next":
            next()
        elif op == "quit":
            exit(0)
        else:
            update()

if __name__ == "__main__":
    main()
