# 2024 Fall COSE102 Final Term Exam
# 2024320333 구민준
# Q1

import pandas as pd

df = pd.read_csv('price.csv')
dates = list(set(df['일자']))

for i in range(len(dates)):
  dates[i] = int(dates[i])

dates.sort()
data_num = len(df)

spot = {}
futures = {}

for i in range(data_num):
  if df.loc[i,'구분'] == 'Spot':
    spot[df.loc[i, '일자']] = int(df.loc[i, '가격'])
  elif df.loc[i, '구분'] == 'Futures':
    futures[df.loc[i, '일자']] = int(df.loc[i, '가격'])

backwardation = []

for date in dates:
  if date in spot and date in futures:
    if spot[date] > futures[date]:
      backwardation.append(date)

n = int(input())

print(backwardation[n - 1])