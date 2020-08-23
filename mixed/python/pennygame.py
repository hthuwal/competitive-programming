t=int(raw_input())
while(t):
    n=raw_input()
    str=raw_input()
    print str.count('TTT'),
    print str.count('TTH'),
    print str.count('THT'),
    print str.count('THH'),
    print str.count('HTT'),
    print str.count('HTH'),
    print str.count('HHT'),
    print str.count('HHH')
    t-=1
