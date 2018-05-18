a=raw_input()
q=int(raw_input())
while(q):
	p,q,r,s=map(int,raw_input().split())
	hc=a[p-1:q]
	fz=a[r-1:s]
	if(hc==fz):
		print "Yes"
	else:
		print "No"
	q-=1