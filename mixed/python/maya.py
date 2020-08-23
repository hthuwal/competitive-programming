values = {'S':0,'.':1,'..':2,'...':3,'....':4,'-':5,'. -':6,'.. -':7,'... -':8,'.... -':9,'- -':10,'. - -':11,'.. - -':12,'... - -':13,'.... - -':14,'- - -':15,'. - - -':16,'.. - - -':17,'... - - -':18,'.... - - -':19}
# print str(values);
while(1):
	n = int(raw_input())
	if(n==0):
		exit()
	ans = 0
	for i in range(n-1,-1,-1):
		string = raw_input()
		string.strip()
		if(i<2):
			mul = 20**i
		else:
			mul = 360*(20**(i-2))
		ans += (mul*values.get(string))
	
	print ans
	string = raw_input()