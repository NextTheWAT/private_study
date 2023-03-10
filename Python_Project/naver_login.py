from selenium import webdriver
import time
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.common.action_chains import ActionChains
import pyperclip


driver = webdriver.Chrome(r"C:/Users/User/Desktop/chromedriver_win32/chromedriver.exe")
driver.implicitly_wait(10) #10초대기 설정
driver.get("https://www.naver.com")

from selenium.webdriver.common.by import By
driver.find_element(By.CLASS_NAME,'link_login').click()

user = {'id':'jh4161126','pw':'@Hjdy08254'}

#이미지 캡차 발생
#driver.find_element(By.ID,'id').send_keys(user['id'])
#driver.find_element(By.ID,'pw').send_keys(user['pw'])
#driver.find_element(By.CLASS_NAME, 'btn_global').click()

driver.find_element(By.ID,'id').click()
pyperclip.copy(user['id'])
ActionChains(driver).key_down(Keys.CONTROL).send_keys('v').key_up(Keys.CONTROL).perform()

driver.find_element(By.ID,'pw').click()
pyperclip.copy(user['pw'])
ActionChains(driver).key_down(Keys.CONTROL).send_keys('v').key_up(Keys.CONTROL).perform()

driver.find_element(By.XPATH,'//*[@id="log.login"]').send_keys(Keys.ENTER)


# https://pythonblog.co.kr/coding/25/
