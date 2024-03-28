INF = 99999
anser = []
def floydWarshall(row, col, weight,num_vertices, graph):
    graph[row][col] = weight
    graph[col][row] = weight
    ans = 0
    dist = [row[:] for row in graph]
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    for i in range(num_vertices):
        for j in range(num_vertices):
            ans += dist[i][j]
    ans = ans / 2
    anser.append(ans)

def printSolution(num_vertices, dist):
    for i in range(num_vertices):
        for j in range(num_vertices):
            if dist[i][j] == INF:
                print("%7s" % ("INF"), end=" ")
            else:
                print("%7d\t" % (dist[i][j]), end=' ')
            if j == num_vertices - 1:
                print()

def updateWeight(dist, row, col, weight):
    dist[row][col] = weight

def getUpdateInput():
    row,col,weight = map(int,input().split())
    return row, col, weight

def get_adjacency_matrix():
    vertices = int(input())
    adjacency_matrix = []
    for _ in range(vertices):
        row = list(map(int, input().split()))
        adjacency_matrix.append(row)

    return vertices, adjacency_matrix

num_vertices, dist = get_adjacency_matrix()


n = input()
for i in range(int(n)):
    row, col, weight = getUpdateInput()
    floydWarshall(row - 1, col - 1, weight,num_vertices, dist)

for i in anser:
    print(int(i), end=" ")


