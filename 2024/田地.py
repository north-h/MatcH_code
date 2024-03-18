x, y, z = map(float, input().split())
a = x * y / z + x * z / y + y * z / x
b = (x + y + z)
if a == b:
    print('=')
elif a < b:
    print('<')
else:
    print('>')
