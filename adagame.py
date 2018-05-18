def memo(f):
    table = {}

    def inner(o, n, t):
        key = o+n+str(t)
        if key not in table:
            table[key] = f(o, n, t)

        return table[key]
    return inner


@memo
def ans(o, n, t):
    if t == 0:
        if int(n) > int(o):
            return "Ada"
        else:
            return "Vinit"
    else:
        x = list(n)
        if(t % 2 == 0):
            me = "Vinit"
            opp = "Ada"
        else:
            me = "Ada"
            opp = "Vinit"

        for i in range(len(x)):
            temp = x[i]
            x[i] = str((int(x[i])+1) % 10)
            nextcand = "".join(x)

            if(ans(o, nextcand, t-1) != opp):
                return me
            x[i] = temp

        return opp

t = int(raw_input().strip())
while(t > 0):
    n, c = raw_input().strip().split()
    print ans(n, n, int(c))
    t -= 1
