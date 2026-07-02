from math import floor

days = int(input("输入你在洛谷打卡的天数："))
year = floor(days / 365)
day = days - year * 365
print(f"今天是洛谷历 {year} 年 {day} 天")


