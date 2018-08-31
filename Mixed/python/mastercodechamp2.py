import sys
import os
sys.stdin = open("in.txt","rb")
'''Complete the function below.'''

def dfs(n,adj,cost):
    source = 0
    target = n-1
    maxc=-1
    listofpaths=[]
    stack = []
    stack.append([source,str(source+1),0])
    while(len(stack)!=0):
        top = stack.pop()
        cur = top[0]
        path = top[1]
        c = top[2]
        if(cur==target):
            listofpaths.append([path,c])
            if(c>maxc):
                maxc=c
        for i in range(len(adj[cur])):
            npath = path+str(adj[cur][i]+1)
            stack.append([adj[cur][i],npath,c+cost[cur][i]])
    return listofpaths,maxc


def getTolls(input1,input2):
    adj = [[] for i in range(input1)]
    cost = [[] for i in range(input1)]
    
    for each in input2:
        x = map(int,each.split("#"))
        adj[x[0]-1].append(x[1]-1)
        cost[x[0]-1].append(x[2])
    # print adj
    # print cost
    listofpaths,maxc = dfs(input1,adj,cost)
   
    # print maxc
    # listofpaths.sort()
    count = [0]*len(input2)
    chost = [0]*len(input2)
    index = [0]*len(input2)
    path = [[] for i in range(len(input2))]
    for i in range(len(input2)):
        x = input2[i].split("#")
        for paths in listofpaths:
            if x[0]+x[1] in paths[0]:
                index[i]=paths[0].find(x[0]+x[1])
                if(count[i]==1 and paths[1]==chost[i]):
                    count[i]=count[i]
                else:
                    count[i]=count[i]+1
                path[i].append(paths[0])
                chost[i]=paths[1]
    
    # print count
    # print path
    aditi = {}
    for i in range(len(input2)):
        if count[i]==1:
            for pat in path[i]:
                if pat in aditi:
                    aditi[pat].append((index[i],i+1))
                else:
                    aditi[pat]=[(index[i],i+1)]
    
    for key in aditi:
        aditi[key].sort()
    # print aditi
    for i in range(len(listofpaths)):
        listofpaths[i][1]=maxc-listofpaths[i][1]
    update = []
    flag=0
    for each in listofpaths:
        if each[1]!=0:
            if(each[0] not in aditi):
                flag=1
                break
            else:
                if([aditi[each[0]][-1][1],each[1]] not in update):
                    update.append([aditi[each[0]][-1][1],each[1]])
    if(flag==1):
        return ["No Solution"]
    else:
        update = [ str(each[0])+"#"+str(each[1]) for each in update]
        update.insert(0,str(len(update))+"#"+str(maxc));
        return update
    
     


       





ip1 = int(raw_input());
ip2_cnt = 0
ip2_cnt = int(raw_input())
ip2_i=0
ip2 = []
while ip2_i < ip2_cnt:
    try:
        ip2_item = raw_input()
    except:
        ip2_item = None
    ip2.append(ip2_item)
    ip2_i+=1
output = getTolls(ip1,ip2)
for output_cur in output:
    print(str(output_cur))
