name1 = raw_input()
name2 = raw_input()
s = int(raw_input())

plays = list(raw_input())

score1 = 0
score2 = 0

for i in xrange(s):
	if plays[i] == "H":
		if i%2 == 0:
			score1 += 1
		else:
			score2 += 1
	elif plays[i] == "D":
		if i%2 == 0:
			score1 += 2
		else:
			score2 += 2
	elif plays[i] == "O":
		if i%2 == 0:
			score2 += 1
		else:
			score1 += 1
	if score1 >= 7 or score2 >=7:
		break

if score1>score2:
	if score1>7:
		score1 = 7
		message = name1+" has won."
	else:
		message = name1+" is winning."
else:
	if score2>7:
		score2 = 7
		message = name2+" has won."
	else:
		message = name2+" is winning."

print name1, score1, name2, str(score2)+".", message