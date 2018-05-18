def hc(a,b):
        if a%10==0:
            return 0
        elif a%10==1:
            return 1
        elif a%10==2:
            if b%4==1:
                return 2
            elif b%4==2:
                return 4
            elif b%4==3:
                return 8
            elif b%4==0:
                return 6
        elif a%10==3:
            if b%4==1:
                return 3
            elif b%4==2:
                return 9
            elif b%4==3:
                return 7
            elif b%4==0:
                return 1
        elif a%10==4:
            return hc(2,2*b)
        elif a%10==5:
            return 5
        elif a%10==6:
            return (hc(2,b)*hc(3,b))%10
        elif a%10==7:
            if b%4==1:
                return 7
            elif b%4==2:
                return 9
            elif b%4==3:
                return 3
            elif b%4==0:
                return 1
        elif a%10==8:
            return hc(2,3*b)
        elif a%10==9:
            return hc(3,2*b)
t=int(raw_input())
while(t):
    h=raw_input()
    h=h.split(' ')
    a=int(h[0])
    b=int(h[-1])
    print hc(a,b)
    t-=1
