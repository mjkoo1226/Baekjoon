# 2024 Fall COSE102 Final Term Exam
# 2024320333 구민준
# Q2
import requests
from bs4 import BeautifulSoup
import time
from selenium import webdriver
from selenium. webdriver.common.by import By

url = 'https://infodepot.korea.ac.kr/abeek/course/GradCredits.jsp'

specific_options = webdriver.ChromeOptions()
specific_options.add_argument('--headless')
specific_options.add_argument ('--no-sandbox')
driver = webdriver.Chrome(options = specific_options)

driver.get(url)
time.sleep(1)

select = driver.find_element(By.NAME, "sbMajorDiv")
select1 = driver.find_element(By.NAME , "sbCollege")
select2 = driver.find_element(By.NAME, "sbDepartment")

dangwa = input()
hakgwa = input()

select.send_keys('이중전공')
select1.send_keys(dangwa)
select2.send_keys(hakgwa)
time.sleep(1)

button_xpath = '//*[@type="submit"]'
button = driver.find_element(By.XPATH, button_xpath)
button.click()
time.sleep(1)

soup = BeautifulSoup(driver.page_source, 'html.parser')

n = 0

if dangwa == '문과대학':
  if hakgwa == '국어국문학과':
    n = 6
  elif hakgwa == '한국사학과':
    n = 9
  elif hakgwa == '사회학과':
    n = 12
  elif hakgwa == '독어독문학과':
    n = 6
  elif hakgwa == '노어노문학과':
    n = 12
  elif hakgwa == '한학과':
    n = 12
  elif hakgwa == '사학과':
    n = 6
elif dangwa == '공과대학':
  if hakgwa == '화공생명공학과':
    n = 31
  elif hakgwa == '신소재공학부':
    n = 31
  elif hakgwa == '건축학과':
    n = 105
  elif hakgwa == '기계공학부':
    n = 28
  elif hakgwa == '건축사회환경공학부':
    n = 12
  elif hakgwa == '산업경영공학부':
    n = 21
  elif hakgwa == '전기전자공학부':
    n = 28
elif dangwa == '경영대학':
  if hakgwa == '경영학과':
    n = 24
elif dangwa == '정경대학':
  if hakgwa == '정치외교학과':
    n = 9
  elif hakgwa == '경제학과':
    n = 15
  elif hakgwa == '통계학과':
    n = 9
elif dangwa == '생명과학대학':
  if hakgwa == '생명과학부':
    n = 24
  elif hakgwa == '환경생태공학부':
    n = 18
  elif hakgwa == '식품자원경제학과':
    n = 6
elif dangwa == '이과대학':
  if hakgwa == '수학과':
    n = 24
  elif hakgwa == '물리학과':
    n = 31
  elif hakgwa == '화학과':
    n = 30
  elif hakgwa == '지구환경과학과':
    n = 21

print(n)