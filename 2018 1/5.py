word = raw_input()+"abcdefghiklmnopqrstuvwxyz"
key = []
for char in word:
	if char not in key:
		if char == "j":
			char = "i"
		key.append(char)

for i in xrange(25):
	if i%5 != 4:
		print key[i],
	else:
		print key[i]