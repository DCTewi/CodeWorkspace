from selenium import webdriver

customToSay = "还不错！"
driverPath = R"D:\Tools\msedgedriver.exe"

# get page
browser = webdriver.Edge(executable_path=driverPath)
browser.get("https://jw.v.zzu.edu.cn/eams/login.action")
browser.implicitly_wait(10)

import os
os.system("cls")
ignore = input("Please loggin and enter sth")

# get links
browser.get("https://jw.v.zzu.edu.cn/eams/quality/stdEvaluate.action")
browser.implicitly_wait(10)

buttons = browser.find_elements_by_xpath('//span[@class="eval"]/..')
links = []
for button in buttons:
    link = button.get_attribute('href')
    if link.startswith('https://jw.v.zzu.edu.cn/eams/quality/stdEvaluate!answer.action?'):
        links.append(link)

# do!
import time
for link in links:
    print("Now " + link)
    browser.get(link)

    radios = browser.find_elements_by_xpath('//input[@value="0"]')
    for radio in radios:
        radio.click()
    textarea = browser.find_element_by_tag_name("textarea").send_keys(customToSay)
    
    browser.find_element_by_id("sub").click()
    
    alert = browser.switch_to_alert()
    alert.accept()
    browser.implicitly_wait(10)

    time.sleep(0.5)
