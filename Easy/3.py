a = int(raw_input())
while a != 0:
	b = a
	count = 0
	while b != 1:
		if b % 2 == 0:
			b /= 2
		else:
			b = 3*b + 1
		count += 1
	print count
	a = int(raw_input())