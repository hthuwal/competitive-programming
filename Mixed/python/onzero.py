import sys
sys.stdin = open("in.txt","rb")
'''Reason why we don't have to visit the same state again: 
Let x and y be strings, which have same state. Let xx be 
the smaller one and zz be another string which when appended 
to yy gives us a number divisible by nn. If so, then we 
can also append this string to xx, which is smaller than yy,
 and still get a number divisible by n. So we can safely 
 ignore yy, as the smallest result will be obtained via 
 xx only.'''
def ans(n):
    dict = {} ## to store the lowest string corresponding to each remainder
    q = ['1']
    while(1):
        top = q.pop()
        if(int(top)%n==0):
            return top
        else:
            if(int(top)%n not in dict): ## if this remainder has already been encounterd before no need to follow it again
                dict[int(top)%n]=top
                q.insert(0,top+'0')
                q.insert(0,top+'1')

n = int(raw_input().strip())

while(n!=0):
    x = int(raw_input().strip())
    print ans(x)
    n=n-1