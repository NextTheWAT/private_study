from selenium import webdriver

from selenium.webdriver.common.keys import Keys

import time


dv = webdriver.Chrome(r'C:/Users/User/Desktop/chromedriver_win32/chromedriver.exe')

dv.get("https://www.naver.com")

time.sleep(100)