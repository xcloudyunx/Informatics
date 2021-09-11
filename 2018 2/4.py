T = list(raw_input())
F = list(raw_input())

for p in F:
	if p in ["M", "D"]:
		T.pop(0)
	elif p == "A":
		T.remove("B")

if len(T) == 0:
	print "None"
else:
	final = ""
	for t in T:
		final += t
	print final