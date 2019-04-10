#Multi-Rename Script
#

import os

extName = input('请输入你想批量重命名的文件扩展名(例如 \'txt\'):')
nameRoot = input('请输入命名前缀:')
nameListAll = os.listdir()
nameList = []

for name in nameListAll:
    if name.endswith('.' + extName):
        nameList.append(name)
        print(name)
input('检查到以上文件，按回车键继续...')

index = 'A'
for name in nameList:
    os.rename(name, nameRoot + '-' + index + '.' + extName)
    index = chr(ord(index) + 1)

input('已完成，回车键退出...')
os._exit(0)

#
#Code by DCTewi on Apr 21st 2018
#Copyright (c) 2018 dctewi.com
