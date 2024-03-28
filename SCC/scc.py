from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs(self, vertex, visited, stack):
        visited[vertex] = True
        for neighbor in self.graph[vertex]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, stack)
        stack.append(vertex)

    def transpose(self):
        transposed_graph = Graph(self.vertices)
        for vertex in self.graph:
            for neighbor in self.graph[vertex]:
                transposed_graph.add_edge(neighbor, vertex)
        return transposed_graph

    def second_dfs(self, vertex, visited):
        visited[vertex] = True
        for neighbor in self.graph[vertex]:
            if not visited[neighbor]:
                self.second_dfs(neighbor, visited)

    def kosaraju_scc(self):
        stack = []
        visited = [False] * (self.vertices)

        for vertex in range(self.vertices):
            if not visited[vertex]:
                self.dfs(vertex, visited, stack)

        transposed_graph = self.transpose()

        visited = [False] * (self.vertices)

        scc_count = 0
        while stack:
            vertex = stack.pop()
            if not visited[vertex]:
                transposed_graph.second_dfs(vertex, visited)
                scc_count += 1

        return scc_count

num_vertices, num_edges = map(int, input().split()) 
g = Graph(num_vertices)

for _ in range(num_edges):
    u, v = map(int, input().split())
    g.add_edge(u - 1, v - 1)

result = g.kosaraju_scc()
print(result)
