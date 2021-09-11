def checkConnection(coordinate):
	global coordinates
	global landSize
	global checkedCoordinates
	checkedCoordinates.append(coordinate)
	
	for c in coordinates:
		if c in checkedCoordinates:
			continue
		if coordinate[1] == c[1] and c[0] == coordinate[0]+1:
			landSize += 1
			checkConnection(c)
		if coordinate[0] == c[0] and c[1] == coordinate[1]+1:
			landSize += 1
			checkConnection(c)
		if coordinate[1] == c[1] and c[0] == coordinate[0]-1:
			landSize += 1
			checkConnection(c)
		if coordinate[0] == c[0] and c[1] == coordinate[1]-1:
			landSize += 1
			checkConnection(c)
		

W, H, T = map(int, raw_input().split())
grid = []
for i in xrange(H):
	grid += [list(raw_input())]

coordinates = []

for y in xrange(H):
	for x in xrange(W):
		if grid[y][x] == "#":
			coordinates += [[x, y]]

islands = 0
checkedCoordinates = []
		
for c in coordinates:
	if c in checkedCoordinates:
		continue
	landSize = 1
	checkConnection(c)
	if landSize >= T:
		islands += 1
		
print islands