'''input
2
foo
bar
'''
n = int(raw_input())
for i in range(0,n):
    x = raw_input()
    x = list(x)
    y = []
    for i in range(0,len(x)):
        t = ord(x[-(i+1)])-ord('a')+1
        t = (ord(x[i])-ord('a')+t)%26
        t = chr(ord('a')+t)
        y.append(t)
    y="".join(y)
    print y
    