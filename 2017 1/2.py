grid = [raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]+[raw_input().split(" ")]

answer = raw_input()
while answer != "-1 -1":
	x, y = map(int, answer.split())
	coordinate = grid[y][x]
	if coordinate != "#":
		num = 0
		for row in xrange(10):
			for col in xrange(10):
				if grid[row][col] == coordinate:
					num += 1
		
		if num > 1:
			print "Hit %s" %(coordinate)
		else:
			print "Sunk %s" %(coordinate)
		grid[y][x] = "#"
	else:
		print "Miss"
	answer = raw_input()