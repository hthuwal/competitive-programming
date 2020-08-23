# See fibpol.jpg
import math
t = int(raw_input().strip())
while t:
    ax = int(raw_input().strip())
    D = 5*(ax*ax)+2*ax+1
    d = int(math.sqrt(D))
    if d*d == D:
        print 1
    else:
        print 0
    t-=1