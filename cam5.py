class Graph:
	def __init__(self, n):
		self.n = n
		self.list = [[] for i in range(0,n)]

	def add_edge(self, a, b):
		self.list[a].append(b)
		self.list[b].append(a)

	def dfs(self, s, visited):
		st = []
		if not visited[s]:
			st.append(s)
			while len(st)!=0:
				top = st.pop()
				visited[top]=True
				for nb in self.list[top]:
					if not visited[nb]:
						visited[nb]=True
						st.append(nb)

	def num_connected_components(self):
		visited = [ False for i in range(0, self.n)]
		ans = 0
		for i in range(0, self.n):
			if not visited[i]:
				ans += 1
				self.dfs(i, visited)
		return ans

t = int(input())
# x = input()
while t>0:
	n = int(input())
	g = Graph(n)
	e = int(input())
	for _ in range(e):
		x = input().strip().split()
		a = int(x[0])
		b = int(x[1])
		g.add_edge(a, b)
	print(g.num_connected_components())
	t = t-1
	# x = input()