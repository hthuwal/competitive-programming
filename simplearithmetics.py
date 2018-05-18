t=int(raw_input())
def add(a):
	a=a.split('+')
	c=str(int(a[0])+int(a[-1]))
	a[-1]="+"+a[-1]
	line=""
	la=len(a[0])
	lb=len(a[-1])
	lc=len(c)
	l=max(la,lb,lc)
	for i in range(0,max(lc,lb)):
	    line="-"+line
	ll=len(line)
	for i in range(0,l-la):
	    a[0]=" "+a[0]
	for i in range(0,l-lb):
	    a[-1]=" "+a[-1]
	for i in range(0,l-lc):
	    c=" "+c
	for i in range(0,l-ll):
		line=" "+line
	print a[0]
	print a[-1]
	print line
	print c

def sub(a):
    a=a.split('-')
    c=str(int(a[0])-int(a[-1]))
    a[-1]="-"+a[-1]
    line=""
    la=len(a[0])
    lb=len(a[-1])
    lc=len(c)
    l=max(la,lb,lc)
    for i in range(0,max(lc,lb)):
        line="-"+line
    ll=len(line)
    for i in range(0,l-la):
        a[0]=" "+a[0]
    for i in range(0,l-lb):
        a[-1]=" "+a[-1]
    for i in range(0,l-lc):
        c=" "+c
    for i in range(0,l-ll):
    	line=" "+line
    print a[0]
    print a[-1]
    print line
    print c
    
def mul(a):

    a=a.split('*')
    
    if(len(a[-1])==1):
	    c=str(int(a[0])*int(a[-1]))
	    a[-1]="*"+a[-1]
	    line=""
	    la=len(a[0])
	    lb=len(a[-1])
	    lc=len(c)
	    l=max(la,lb,lc)
	    for i in range(0,max(lc,lb)):
	        line="-"+line
	    ll=len(line)
	    for i in range(0,l-la):
	        a[0]=" "+a[0]
	    for i in range(0,l-lb):
	        a[-1]=" "+a[-1]
	    for i in range(0,l-lc):
	        c=" "+c
	    for i in range(0,l-ll):
	    	line=" "+line
	    print a[0]
	    print a[-1]
	    print line
	    print c
    

    else:
        b=a[-1]
        a=a[0]
        line=""
        finalline=""
        p=int(a)
        q=int(b)
        c=str(p*q)
        b="*"+b
        hc=[a,b,line]
        i=0

        while(q>0):
            hc.append(str(p*(q%10)))
            for j in range(0,i):
                hc[-1]=hc[-1]+" "
            q=q/10
            i=i+1
        
        for i in range(0,max(len(hc[1]),len(hc[3])))	:
        	hc[2]="-"+hc[2]

        for i in range(0,max(len(c),len(hc[-1]))):
            finalline="-"+finalline

        hc.append(finalline)
        hc.append(c)
        l=0

        for element in hc:
            if len(element)>l:
                l=len(element)
   

        for i in range(0,len(hc)):
            for j in range(0,l-len(hc[i])):
                hc[i]=" "+hc[i]

        for element in hc:
            print element.rstrip()
            
while(t):
    a=raw_input()
    if '+' in a:
        add(a)
    elif '-' in a:
        sub(a)
    elif '*' in a:
        mul(a)
    print ""
    t-=1
