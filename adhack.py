import sys

def exp(a, b, m):
	a = a%m
	b = b%m
	ans = 1

	while(b>0):
		if(b%2==1):
			ans = (ans * a)%m

		a = (a*a)%m
		b = b>>1
	return ans%m

def multiplicative_inverse(a, m):
	return exp(a, m-2, m)

m = 100000000003
for line in sys.stdin:
	x = list(map(int, line.strip().split()))
	a = ((x[2]-x[1]+m)*multiplicative_inverse(x[1]-x[0]+m, m))%m;
	b = (x[1]-a*x[0]+m)%m;
	a = (a*x[5] + b + m)%m
	print(a)