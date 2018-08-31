import sys
try:
    n = int(sys.argv[1])  
    m = int(sys.argv[2])   
    for i in range(n, m+1):
        print(i)
except:
    print("Error occured")