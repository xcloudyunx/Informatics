n = int(raw_input())
command = raw_input()

while command != "END":
	if command == "BREED!":
		n += int(n*0.1)
	else:
		a, b = command.split(" ")
		b = int(b)
		if a == "RELEASED":
			n += b
		elif a == "DECEASED":
			n -= b
	
	command = raw_input()
	
print n