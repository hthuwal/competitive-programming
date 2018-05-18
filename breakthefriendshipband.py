temp=raw_input()
a=raw_input()
n=len(a)
ans=0
for i in range(0,n):
    j=i+1
    temp=a[i]
    count=1
    flag=0
    while (j%n != i):
        if(a[j%n]=='w' and temp=='w'):
            count+=1
        elif (a[j%n]=='w'):
            count+=1
        elif(a[j%n]!='w' and temp=='w'):
            count+=1
            temp=a[j%n]
        elif(a[j%n]!=temp and flag== 1):
            break
        elif(a[j%n]!=temp and flag==0 ):
            count+=1
            temp=a[j%n]
            flag=1
        else:
            count+=1
        j+=1
    if count > ans:
        ans=count
print ans
