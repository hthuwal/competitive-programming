while(1):
    try:
        n=int(raw_input())
        if n==1:
            print 1
        elif n==0:
            print 0
        else:
            print 2*(n-1)
    except:
        break
