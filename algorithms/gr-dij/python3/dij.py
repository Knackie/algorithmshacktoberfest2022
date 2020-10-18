import sys


  
class graph(): 
    def __init__(self, node_num): 
        self.nodes = node_num 
        self.graph = [[0 for column in range(node_num)] for row in range(node_num)] # to represent edge weight(distance) of each edge in the graph
                    
  
    def print(self, distance): 
        print("node     Distance from start node")
        for node in range(self.nodes): 
            print(node, "     ", distance[node]) 
  

    def find_node_w_min_distance(self, distance, nodes_in_shortest_path): 
        min_distance = sys.maxsize # initialize it with maximum largest value
        for node in range(self.nodes): 
            if distance[node] < min_distance and nodes_in_shortest_path[node] == False: 
                min_distance = distance[node]
                index_of_node_w_min_distance    = node 
        return index_of_node_w_min_distance 
  
    def dijkstra(self, start): 
  
        distance = [sys.maxsize] * self.nodes # array of distance with possible largest values
        distance[start] = 0 # distance of node to itself is 0
        nodes_in_shortest_path = [False] * self.nodes 
  
        for _ in range(self.nodes): 
            current_nearest_node = self.find_node_w_min_distance(distance, nodes_in_shortest_path) 
            nodes_in_shortest_path[current_nearest_node] = True
  
            for v in range(self.nodes): 
                if self.graph[current_nearest_node][v] > 0 and nodes_in_shortest_path[v] == False and distance[v] > distance[current_nearest_node] + self.graph[current_nearest_node][v]: 
                        distance[v] = distance[current_nearest_node] + self.graph[current_nearest_node][v] 
  
        self.print(distance) 

    
g = graph(9) 
g.graph = [[0, 9, 0, 0, 0, 0, 0, 8, 0], 
        [0, 0, 2, 0, 0, 0, 0, 1, 0], 
        [0, 8, 0, 7, 0, 4, 0, 0, 2], 
        [0, 0, 7, 0, 3, 14, 0, 0, 0], 
        [0, 0, 0, 9, 0, 10, 0, 0, 0], 
        [0, 0, 4, 14, 10, 0, 2, 0, 0], 
        [0, 0, 0, 0, 0, 2, 0, 1, 6], 
        [8, 3, 0, 0, 0, 0, 1, 0, 7], 
        [0, 0, 2, 0, 0, 0, 6, 31, 0] 
        ]
  
g.dijkstra(3) 
  