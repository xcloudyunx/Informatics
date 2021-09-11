n = int(raw_input())

outputs = []

for i in xrange(n):
	x, y, z = map(int, raw_input().split())
	output = "Check"
	if x + y + z == 180:
		output = "Seems OK"
	x, y, z = map(str, [x, y, z])
	outputs.append(x+" "+y+" "+z+" "+output)

for line in outputs:
	print line