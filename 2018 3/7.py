N = int(raw_input())
ids = []  # A list of Mindy's IDs
for i in xrange(N):
    ids.append(int(raw_input()))

# Your code here ...
x = ids[N-1]				# x goes through ids with speed "1"
y = ids[ids[N-1]]			# y goes through ids with speed "2"
while x != y:				# They start at index N-1 as none of the values in ids will be able to point to this index
	x = ids[x]				# Because of the duplicate(s), there is one point where there is more than one value in ids pointing to this index thus creating a circle
	y = ids[ids[y]]			# Break out the loop once the two values are equivalent once again
							# 
length = 1					# By leaving y the same but changing x by 1 we can find the circumference of the circle
x = ids[x]					# 
while x != y:				# 
	x = ids[x]				# 
	length += 1				# 
							# 
x = N-1						# Reset x and y to their starting positions
y = N-1						# 
for i in xrange(length):	# Move y one circumference ahead of x
	y = ids[y]				# 
while x != y:				# When the two values meet it will be at the start of the circle where there are two numbers pointing to the same index
	y = ids[y]				# x will be just entering the circle while y would have just completing one loop of the circle
	x = ids[x]				# Move x and y by one until ^.
							# 
print y						# Print out the value