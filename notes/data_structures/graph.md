---
layout: default
title: Graph
---

### Overview
A graph is a non-linear data structure consisting of vertices (nodes) and edges that connect pairs of vertices. Graphs are used to represent relationships and networks, where vertices represent entities and edges represent connections or relationships between them.

### Structure
**Graph Types:**
- **Directed vs Undirected:** Directed graphs have edges with direction (A → B), while undirected graphs have bidirectional edges (A ↔ B)
- **Weighted vs Unweighted:** Weighted graphs assign values to edges (e.g., distance, cost), unweighted graphs treat all edges equally
- **Cyclic vs Acyclic:** Cyclic graphs contain cycles (paths that start and end at the same vertex), acyclic graphs do not

**Representations:**
1. **Adjacency Matrix:** A 2D array where matrix[i][j] indicates an edge from vertex i to vertex j. Space: O(V²)
2. **Adjacency List:** An array/dictionary where each vertex stores a list of adjacent vertices. Space: O(V + E)
3. **Edge List:** A list of all edges as pairs of vertices. Space: O(E)

### Operations

**Add Vertex:**
Add a new vertex to the graph. For adjacency list, add a new key; for adjacency matrix, expand the matrix dimensions.

**Add Edge:**
Create a connection between two vertices. For adjacency list, add vertex to neighbor list; for adjacency matrix, set matrix[i][j] = 1 (or weight).

**Remove Vertex:**
Delete a vertex and all edges connected to it. Remove from adjacency list/matrix and update all references.

**Remove Edge:**
Delete the connection between two vertices. Remove from neighbor list or set matrix[i][j] = 0.

**Traversals:**
- **Depth-First Search (DFS):** Explore as far as possible along each branch before backtracking. Uses stack/recursion. O(V + E) time.
- **Breadth-First Search (BFS):** Explore all neighbors at current depth before moving deeper. Uses queue. O(V + E) time.

**Other Operations:**
- **Find Path:** Determine if path exists between two vertices
- **Shortest Path:** Find minimum distance/cost path (Dijkstra's, Bellman-Ford)
- **Cycle Detection:** Check if graph contains cycles
- **Topological Sort:** Linear ordering of vertices in DAG

### Complexities

**Adjacency List:**
Add Vertex    - O(1)
Add Edge      - O(1)
Remove Vertex - O(V + E)
Remove Edge   - O(E)
Check Edge    - O(V) worst case (O(1) average with hash map)
DFS/BFS       - O(V + E)
Space         - O(V + E)

**Adjacency Matrix:**
Add Vertex    - O(V²) (requires matrix resize)
Add Edge      - O(1)
Remove Vertex - O(V²)
Remove Edge   - O(1)
Check Edge    - O(1)
DFS/BFS       - O(V²)
Space         - O(V²)

### When to Use
**Advantages:**
- Models real-world relationships and networks naturally
- Flexible structure supports various connection patterns
- Efficient traversal algorithms (DFS, BFS) for exploring relationships
- Well-suited for representing non-hierarchical data
- Many established algorithms for pathfinding, optimization, and analysis

**Disadvantages:**
- Can be memory-intensive for dense graphs (many edges)
- More complex to implement and visualize than linear structures
- Some operations can be slow on large graphs
- Adjacency matrix wastes space for sparse graphs
- Can be difficult to scale for very large networks

**Common use cases:**
- Social networks (friends, followers, connections)
- Maps and navigation systems (cities as vertices, roads as edges)
- Web page linking and search engines (PageRank)
- Dependency resolution (package managers, build systems)
- Network routing and telecommunications
- Recommendation systems
- Task scheduling with dependencies (project management)
- Molecular structures and chemical compounds

### Visual Representation
```
Undirected Graph Example:
    A --- B
    |     |
    |     |
    C --- D --- E

Adjacency List Representation:
A: [B, C]
B: [A, D]
C: [A, D]
D: [B, C, E]
E: [D]

Adjacency Matrix Representation:
    A  B  C  D  E
A [ 0  1  1  0  0 ]
B [ 1  0  0  1  0 ]
C [ 1  0  0  1  0 ]
D [ 0  1  1  0  1 ]
E [ 0  0  0  1  0 ]

Directed Weighted Graph Example:
    A --5--> B
    |        |
    3        2
    |        |
    v        v
    C <-4--- D

Adjacency List Representation:
A: [(B, 5), (C, 3)]
B: [(D, 2)]
C: []
D: [(C, 4)]
```

### Implementation(s)

**Python:**
```python
from collections import deque, defaultdict

class Graph:
    def __init__(self, directed=False):
        """Initialize graph with adjacency list representation."""
        self.graph = defaultdict(list)
        self.directed = directed

    def add_vertex(self, vertex):
        """Add a vertex to the graph."""
        if vertex not in self.graph:
            self.graph[vertex] = []

    def add_edge(self, u, v, weight=None):
        """Add an edge between vertices u and v."""
        if weight is not None:
            self.graph[u].append((v, weight))
            if not self.directed:
                self.graph[v].append((u, weight))
        else:
            self.graph[u].append(v)
            if not self.directed:
                self.graph[v].append(u)

    def remove_vertex(self, vertex):
        """Remove a vertex and all edges connected to it."""
        if vertex in self.graph:
            # Remove the vertex
            del self.graph[vertex]
            # Remove all edges pointing to this vertex
            for v in self.graph:
                self.graph[v] = [neighbor for neighbor in self.graph[v]
                                if (neighbor if not isinstance(neighbor, tuple)
                                    else neighbor[0]) != vertex]

    def remove_edge(self, u, v):
        """Remove edge between u and v."""
        if u in self.graph:
            self.graph[u] = [neighbor for neighbor in self.graph[u]
                           if (neighbor if not isinstance(neighbor, tuple)
                               else neighbor[0]) != v]
        if not self.directed and v in self.graph:
            self.graph[v] = [neighbor for neighbor in self.graph[v]
                           if (neighbor if not isinstance(neighbor, tuple)
                               else neighbor[0]) != u]

    def has_edge(self, u, v):
        """Check if edge exists between u and v."""
        if u not in self.graph:
            return False
        for neighbor in self.graph[u]:
            vertex = neighbor if not isinstance(neighbor, tuple) else neighbor[0]
            if vertex == v:
                return True
        return False

    def get_vertices(self):
        """Return all vertices in the graph."""
        return list(self.graph.keys())

    def get_neighbors(self, vertex):
        """Return all neighbors of a vertex."""
        return self.graph.get(vertex, [])

    def dfs(self, start, visited=None):
        """Depth-first search traversal."""
        if visited is None:
            visited = set()
        visited.add(start)
        result = [start]

        for neighbor in self.graph.get(start, []):
            vertex = neighbor if not isinstance(neighbor, tuple) else neighbor[0]
            if vertex not in visited:
                result.extend(self.dfs(vertex, visited))

        return result

    def bfs(self, start):
        """Breadth-first search traversal."""
        visited = set([start])
        queue = deque([start])
        result = []

        while queue:
            vertex = queue.popleft()
            result.append(vertex)

            for neighbor in self.graph.get(vertex, []):
                v = neighbor if not isinstance(neighbor, tuple) else neighbor[0]
                if v not in visited:
                    visited.add(v)
                    queue.append(v)

        return result

    def has_path(self, start, end):
        """Check if path exists between start and end vertices."""
        if start == end:
            return True
        visited = set([start])
        queue = deque([start])

        while queue:
            vertex = queue.popleft()
            for neighbor in self.graph.get(vertex, []):
                v = neighbor if not isinstance(neighbor, tuple) else neighbor[0]
                if v == end:
                    return True
                if v not in visited:
                    visited.add(v)
                    queue.append(v)

        return False

    def __str__(self):
        """String representation of the graph."""
        result = []
        for vertex in sorted(self.graph.keys()):
            result.append(f"{vertex}: {self.graph[vertex]}")
        return "\n".join(result)

# Example usage
if __name__ == "__main__":
    # Create undirected graph
    g = Graph(directed=False)
    g.add_edge('A', 'B')
    g.add_edge('A', 'C')
    g.add_edge('B', 'D')
    g.add_edge('C', 'D')
    g.add_edge('D', 'E')

    print("Graph:")
    print(g)
    print("\nDFS from A:", g.dfs('A'))
    print("BFS from A:", g.bfs('A'))
    print("Path A to E:", g.has_path('A', 'E'))

    # Create directed weighted graph
    wg = Graph(directed=True)
    wg.add_edge('A', 'B', 5)
    wg.add_edge('A', 'C', 3)
    wg.add_edge('B', 'D', 2)
    wg.add_edge('D', 'C', 4)

    print("\nWeighted Directed Graph:")
    print(wg)
```

### External Links
- [Visualgo - Graph Data Structures](https://visualgo.net/en/graphds) - Interactive visualization of graph representations and algorithms
- [GeeksforGeeks - Graph Data Structure](https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/) - Comprehensive guide with examples and algorithms
- [Wikipedia - Graph Theory](https://en.wikipedia.org/wiki/Graph_theory) - Mathematical foundations and theory behind graphs

---

[Up](./README.md)
