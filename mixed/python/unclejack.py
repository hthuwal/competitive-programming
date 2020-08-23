from math import factorial
while(1):
	a,b = raw_input().strip().split(' ');
	a = int(a);
	b = int(b);
	if(a==0 and b==0):
		break
	print a**b;
	