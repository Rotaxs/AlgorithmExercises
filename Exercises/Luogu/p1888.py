def gcd(a, b):
    """
        利用辗转相除法求两个数的最大公因数
    """
    return a if b == 0 else gcd(b, a % b)

str = input()
# 用空格分割字符串并返回一个列表
a, b, c = str.split(" ")
a = int(a)
b = int(b)
c = int(c)

if a > b:
    a, b = b, a
if b > c:
    b, c = c, b
if a > b:
    a, b = b, a

factor = gcd(a, c)
print(f"{int(a/factor)}/{int(c/factor)}")

