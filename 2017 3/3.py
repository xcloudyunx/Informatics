import math

a = int(raw_input())
b = int(math.sqrt(a))

c = a - b**2
if c == 0:
	y = b-1
	x = b-1
elif c%2 == 1:
	y = c/2
	x = b
else:
	y = c/2-1
	x = b

print x**2 + y**2