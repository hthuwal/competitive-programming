##Each index, if it is a power of 2, will store the sum of all elements before that. And we will apply this 
##repetitively so as to get what each index will store.
def hc(index,n):
	index+=1
	while(index<=n):
		print index,
		index = index + (index & (-index))

def jp(index,n):
	index+=1
	while(index>0):
		print index,
		index = index - (index & (-index))

for i in range(0,12):
	hc(i,12)
	print

print "************************************************************************************"

for i in range(0,12):
	jp(i,12)
	print