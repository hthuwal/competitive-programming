'''input
4
3
3 0
0 1
1 2
1
'''
from collections import defaultdict

class Graph:
	V=0;
	adj = defaultdict(list)

	def __init__(self,v):
		self.V=v
		for i in range(v):
			self.adj[i]=[]

	def addedge(self,a,b):
		self.adj[a].append(b)
		self.adj[b].append(a)

	def printy(self):
		for x in self.adj:
			print x,self.adj[x]

	def dfs(self,s,visited):
		stack = list()
		stack.append(s)
		while(len(stack)>0):
			top = stack.pop()
			visited[top]=True
			for i in self.adj[top]:
				if(visited[i]==False):
					stack.append(i)

	def connectedornot(self,x):
		visited = [False for i in range(self.V)]
		count=0
		self.dfs(0,visited)
		# print visited
		for i,value in enumerate(visited):
			if  value==False and i!=x:
				return False
		return True

	def removevertex(self,x):
		for i in self.adj:
			if i==x:
				del self.adj[i][:]
			elif x in self.adj[i]:
				self.adj[i].remove(x)

n=int(raw_input())
g=Graph(n)
k=int(raw_input())
for i in range(k):
	a,b=[int(x) for x in raw_input().split()]
	g.addedge(a,b)
# g.printy()
x=int(raw_input())
# print x
g.removevertex(x)
# g.printy()
if g.connectedornot(x)==True:
	print "Connected"
else:
	print "Not Connected"

