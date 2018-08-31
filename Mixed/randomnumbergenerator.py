from random import randint

fp = open("in.txt","wb")
x=1000
fp.write(str(x)+"\n")
for i in range(0,x):
    fp.write(str(randint(0,(2**63)-1))+"\n")

