alpha = 0
beta = 90
command, angle = raw_input().split()

while command != "END":
	angle = int(angle)

	if command == "BOOST":
		beta += angle
	elif command == "TRAVEL":
		alpha += angle
		beta  += angle
		
	command, angle = raw_input().split()
	
while alpha >= 360:
	alpha -= 360
while beta >= 360:
	beta -= 360
	
object = int(raw_input())

print alpha, beta
if object >= alpha and object <= beta:
	print "Missile located."
else:
	print "Missile unlocatable."