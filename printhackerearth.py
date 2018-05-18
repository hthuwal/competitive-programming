n = int(raw_input())
x = raw_input()
d = {'h':0,'a':0,'c':0,'k':0,'e':0,'r':0,'t':0}
x = list(x)
for c in x:
	if(d.has_key(c)):
		d[c]=d[c]+1

d['a']=d['a']/2
d['e']=d['e']/2
d['h']=d['h']/2
d['r']=d['r']/2

min = 100000000
for c in d:
	if(d[c]<min):
		min = d[c]

print min