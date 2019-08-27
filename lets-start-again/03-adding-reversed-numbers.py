t = int(input().strip())
while(t > 0):
    a, b = input().strip().split()
    a = int(''.join(reversed(a)))
    b = int(''.join(reversed(b)))
    ans = str(a + b).rstrip('0')
    print(''.join(reversed(ans)))
    t -= 1
