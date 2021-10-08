from queue import Queue

def bfs(graph):
	queue = Queue()
	visited = {}
	distance = {}
	parent = {}
	bfs_list = []

	for node in graph.keys():
		visited[node] = False
		distance[node] = -1
		parent[node] = None

	start = "A" #sourse
	visited[start] = True #marking starting node as visited
	distance[start] = 0 #setting level as 0
	queue.put(start)

	while not queue.empty():
		visit = queue.get()
		bfs_list.append(visit)

		for v in graph[visit]:
			if not visited[v]:
				visited[v] = True
				distance[v] = distance[visit] + 1
				parent[v] = visit
				queue.put(v)
	return bfs_list


if __name__ == "__main__":
    
	graph = {
		"A":["B", "D"],
		"B":["A","C"],
		"C":["B"],
		"D":["A", "E", "F"],
		"E":["D","F","G"],
		"F":["D","E","H"],
		"G":["E","H"],
		"H":["G","F"]
	}

	print(bfs(graph))