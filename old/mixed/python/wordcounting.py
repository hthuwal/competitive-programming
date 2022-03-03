t = int(raw_input())
while(t):
	string = raw_input()
	string = string.split()
	pre = ""
	max_uptill_now = 0
	current_max = 0
	for word in string:	 
		if(len(word)==len(pre)):
			current_max+=1	
		else:
			current_max=1
			pre = word
		if(current_max>max_uptill_now):	
			max_uptill_now=current_max

	print max_uptill_now
	t-=1
