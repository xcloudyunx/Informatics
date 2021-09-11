R, C = map(int, raw_input().split())

grid = []

for i in xrange(R):
	a = raw_input().split()
	try:
		grid.append(map(int, a))
	except ValueError:
		for j in xrange(len(a)):
			try:
				a[j] = int(a[j])
			except ValueError:
				x = j
				y = i
				continue
		grid.append(a)
				
for i in xrange(R):
	for j in xrange(R):
		if grid[j][x] == "x":
			continue
		elif i+1 == grid[j][x]:
			break
	else:
		grid[y][x] = i+1
		for k in grid:
			for l in k:
				if l != k[C-1]:
					print l,
				else:
					print l
		break