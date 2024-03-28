from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.graph1 = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def add_edge_v(self, u, v):
        self.graph1[u].append(v)

    def is_cyclic_util(self, vertex, visited, recursion_stack):
        visited.add(vertex)
        recursion_stack.add(vertex)
        
        for neighbor in self.graph1[vertex]:
            if neighbor not in visited:
                if self.is_cyclic_util(neighbor, visited, recursion_stack):
                    return True
            elif neighbor in recursion_stack:
                return True

        recursion_stack.remove(vertex)
        return False

    def is_cyclic(self, connected_component):
        visited = set()
        recursion_stack = set()

        for vertex in connected_component:
            if vertex not in visited:
                if self.is_cyclic_util(vertex, visited, recursion_stack):
                    return True

        return False

    def find_connected_components(self):
        visited = set()
        connected_components = []

        for vertex in self.graph:
            if vertex not in visited:
                connected_component = []
                self.dfs(vertex, visited, connected_component)
                connected_components.append(connected_component)  

        return connected_components

    def dfs(self, vertex, visited, connected_component):
        visited.add(vertex)
        connected_component.append(vertex)
        
        for neighbor in self.graph[vertex]:
            if neighbor not in visited:
                self.dfs(neighbor, visited, connected_component)

g = Graph()
g1 =Graph()
num_vertices, num_edges = map(int, input().split()) 

for _ in range(num_edges):
    u, v = map(int, input().split())
    g.add_edge(u, v)
    g.add_edge_v(u, v)

connected_components = g.find_connected_components()
component_count = len(connected_components)
cnt = 0




for component in connected_components:
    has_cycle = g.is_cyclic(component)
    #print(f"Connected Component: {component}, Has Cycle: {has_cycle}")
    if has_cycle == False:
        cnt = cnt + 1

print(len(g.graph) - cnt)