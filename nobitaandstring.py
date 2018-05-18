t=int(raw_input())
while(t):
	hc=raw_input()
	hc=hc.split()
	for i in range (len(hc)-1,-1,-1):
		print hc[i]+' ',
	print
	t-=1
