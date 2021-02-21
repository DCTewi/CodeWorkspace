#coding=utf-8

import requests
import shutil
import time
import json
import os

from requests.api import options

upUid = "1427846"
pageCount = 50

class Fan:
    def __init__(self, uid, nick, face) -> None:
        self.uid = uid
        self.nick = nick
        self.face = face

    def __eq__(self, o: object) -> bool:
        return o.uid == self.uid

    def __str__(self) -> str:
        return "Uid: {},\t\t Nickname: {},\t\t Face: {}".format(self.uid, self.nick, self.face)

def fromJsonToFan(fan : Fan):
    return Fan(fan['uid'], fan['nick'], fan['face'])

def fromFanToJson(fan):
    return fan.__dict__



def getFanListApiUrl(uid : str, page : int, pagecapacity = 20) -> str:
    return "https://api.bilibili.com/x/relation/followers?vmid={}&pn={}&ps={}&jsonp=jsonp".format(uid, page, pagecapacity)

def getUserStatsUrl(uid : str) -> str:
    return "https://api.bilibili.com/x/relation/stat?vmid={}&jsonp=jsonp".format(uid)

def getCookieTxt() -> dict:
    cookies = {}
    rawstr = []
    with open("cookie.txt", encoding="utf-8") as f:
        rawstr = f.read().split(';')
    for s in rawstr:
        key, value = s.strip().split('=', 1)
        cookies[key] = value
    return cookies

def getCurrentFanList(uid : str, cookie : dict) -> list:
    fanCount = requests.get(getUserStatsUrl(uid), cookies=cookie).json()['data']['follower']
    print("Now Fans Count: {}".format(fanCount))

    totalPage = fanCount // pageCount + (1 if fanCount % pageCount != 0 else 0)
    print("Total Pages: {}".format(totalPage))

    fanNameList = []
    for i in range(1, totalPage + 1):
        print("GETing page: {}/{}".format(i, totalPage))
        pageList = requests.get(getFanListApiUrl(uid, i, pageCount), cookies=cookie).json()['data']['list']
        for fan in pageList:
            mid = fan['mid']
            nick = fan['uname']
            face = fan['face']
            fanNameList.append(Fan(mid, nick, face))
        time.sleep(0.1)

    return fanNameList

def getLocalFans() -> list:
    with open("fans.json", encoding="utf-8") as f:
        return json.loads(f.read(), object_hook=fromJsonToFan)

def saveLocalFans(fansList : list):
    shutil.copy("fans.json", "history/fans-{}.json".format(time.strftime("%Y-%m-%d %H-%M-%S", time.localtime())))
    jsonstr = json.dumps(fansList, default=fromFanToJson, sort_keys=True, indent=4)
    with open("fans.json", encoding="utf-8", mode="w") as f:
        f.write(jsonstr.encode('latin-1').decode('unicode_escape'))

def getChangeLog(uid: str):
    localFans = getLocalFans()
    nowFans = getCurrentFanList(uid, getCookieTxt())

    fanInfoChanged = False
    dateString = time.strftime("%Y-%m-%d %H-%M-%S", time.localtime())
    changeLog = "Changelog: {}\n".format(dateString)

    changeLog += "\n[Unfollowed]\n"
    for fan in localFans:
        if fan not in nowFans:
            print("User: [{}]{} unfollowed you".format(fan.uid, fan.nick))
            changeLog += "{}\n".format(fan)
            fanInfoChanged = True

    changeLog += "\n[New Follow]\n"
    for fan in nowFans:
        if fan not in localFans:
            print("New Fan: [{}]{}".format(fan.uid, fan.nick))
            changeLog += "{}\n".format(fan)
            fanInfoChanged = True

    if not fanInfoChanged:
        print("No new fans or unfollow")

    with open("changelog/changelog-{}.log".format(dateString), encoding="utf-8", mode="w") as f:
        f.write(changeLog)

    saveLocalFans(nowFans)

def main():
    if not os.path.exists('changelog'):
        os.mkdir('changelog')
    if not os.path.exists('history'):
        os.mkdir('history')
    if not os.path.exists('fans.json'):
        with open('fans.json', mode="w+", encoding="utf-8") as f:
            f.write("[]")
    getChangeLog(upUid)

main()
