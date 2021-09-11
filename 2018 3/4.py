num = raw_input()
spell = raw_input()

if "AAAAA" in spell or "ABBA" in spell or "ABCABC" in spell:
	print "UNSAFE"
else:
	print "SAFE"