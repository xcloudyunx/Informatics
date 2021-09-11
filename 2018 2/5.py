message = list(raw_input())
mlen = len(message)

for i in xrange(mlen):
	if message[i] == "j":
		message[i] = "i"

grid = [["w", "h", "e", "a", "t"], ["s", "o", "n", "b", "c"], ["d", "f", "g", "i", "k"], ["l", "m", "p", "q", "r"], ["u", "v", "x", "y", "z"]]

pairs = []

while len(message) != 0:
	if len(message) > 1:
		pair = message[0:2]
		if pair[0] == pair[1]:
			pair[1] = "x"
			message.pop(0)
		else:
			message.pop(0)
			message.pop(0)
	elif len(message) == 1:
		pair = [message[0], "x"]
		message.pop(0)
	pairs.append(pair)

def locate(s):
	for y in xrange(5):
		for x in xrange(5):
			if grid[y][x] == s:
				return x, y

encoded = []
				
for d in pairs:
	x1, y1 = locate(d[0])
	x2, y2 = locate(d[1])
	if x1 == x2:
		y1 += 1
		y2 += 1
		if y1 == 5:
			y1 = 0
		elif y2 == 5:
			y2 = 0
	elif y1 == y2:
		x1 += 1
		x2 += 1
		if x1 == 5:
			x1 = 0
		elif x2 == 5:
			x2 = 0
	else:
		x = x1
		x1 = x2
		x2 = x
	encoded.append(grid[y1][x1])
	encoded.append(grid[y2][x2])
	
print "".join(encoded)