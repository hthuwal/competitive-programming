while(1):
	hc=raw_input()
	if(hc=="END"):
		break
	i=1
	while(1):
		l=len(hc)
		l=str(l)
		if(l==hc):
			break
		else:
			i+=1
			hc=l
	print i