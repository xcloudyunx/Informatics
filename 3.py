n, m = map(int, raw_input().split())
a = raw_input()[::-1]
b = raw_input()
s = int(raw_input())

o = list(a)+list(b)
f =[None]*(n+m)*51

for i in xrange(n):
	f[50+max(i, i+s+i+1-n)] = o[i]

j = m-1
for i in xrange(m):
	f[50+min(i+n, i+n-s-j-1+m)] = o[i+n]
	j -= 1
	
f = filter(None, f)
print "".join(f)