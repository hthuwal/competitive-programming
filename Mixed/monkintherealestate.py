t=int(raw_input())
while(t):
	hc= []
	e=int(raw_input())
	for i in range(0,e):
		a,b=raw_input().split()
		a=int(a)
		b=int(b)
		hc.append(a)
		hc.append(b)
	hc=set(hc)
	print len(hc)
	t-=1