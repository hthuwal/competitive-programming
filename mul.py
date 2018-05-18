n = int(raw_input())
while(n!=0):
	h = raw_input()
	h = h.split(" ")
	a = int(h[0])
	b = int(h[-1])
	print a*b
	n-=1