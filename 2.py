x, y, z = map(int, raw_input().split())
c = max(x, y, z)
b = min(max(x, y),max(x, z),max(y, z))
a = min(x, y, z)

arrangement = raw_input()
for i in xrange(3):
	if arrangement[i] == "A":
		print a,
	elif arrangement[i] == "B":
		print b,
	else:
		print c,