
**1. Create a theoretical graph using a pen and paper OR electronically.**

<img width="989" height="733" alt="GraphLab10" src="https://github.com/user-attachments/assets/278087c4-3df1-436e-8b94-de4927a0e1a5" />


**2. Implment the graph created in step 1 and apply breadth and depth-first search alogrithms using C++.**

The first step to creating our graph in code is to create the adjacency matrix that makes up our graph. The adjacency matrix that makes up our graph keeps track of the connections each vertex has with other vertices, and is done in a square matrix consisting of 0s and 1s (0 represent no connection, 1 represents a connection). We have this method called "addEdge", which will mark a vertex being connected with another in the matrix. Note that the connection will go both ways in this example, so if we want to create an edge from vertex 1 to vertex 3, we also have to make an edge from vertex 3 to vertex 1.

For the Breadth-First Search, we are going to be exploring vertices by level. This means that vertices closest to the starting vertex will appear first, and ones further away will appear later, making this algorithm good for finding the shortest path from one vertex to another. In order to implement this algorithm, we'll want to keep track of which vertices have to be visited (so that we don't go to the same one more than once) and the order of which they were visited (we'll use a queue for this, since it is FIFO).

Here is what the process looks like at each level for a Breadth-First Search on our graph: <br>
Level 0: <br>
- Start at starting vertex (0 in this case).
- Add 0 to queue and result
- Visit vertex 0 and remove from queue
Level 1: <br>
- Get neighbors from 0 (in this case, 1 and 4).
- Add neighbors to queue.
- Visit vertex 1 and 4 (vertex 1 will be visited first since it is higher in the queue) and add to result.
- Remove vertex 1 and 4 from the queue.
Level 2: <br>
- Get unvisited neighbors from 1 (in this case, 2 and 3).
- Visit vertex 2 and 3 + remove them from the queue.

The BFS will return the following result: ```[0, 1, 4, 2, 3]```

For the Depth-First Search, we are going to be exploring every vertex of the graph by going as deep as possible down one path before backtracking to another branch. Think of it like walking through a maze, where you may go down one path until you reach a dead-end, so you backtrack to find another way to escape.

Here is what the process looks like for a Depth-First Search on our graph: <br>
Path 1: <br>
- Start at starting vertex (0 in this case)
- Visit 0
- Go to neighbor (we'll go to 1 before 4)
- Visit 1
- Go to neighbor (we'll go to 2 before 3)
- Visit 2
- Go to neighbor (only available neighbor here is 3)
- Visit 3 (No more neighbors to visit, so we'll backtrack)
Backtrack (from 3):
- Move back to 2 (no more unvisited neighbors)
- Move back to 1 (no more unvisited neighbors)
- Move back to 0 (one more neighbor to visit)
- Visit 4

The DFS will return the following result: ```[0, 1, 2, 3, 4]```

**3. Compare both search algorithms in the context of Big O Notations.**

In Big O Notation, the time complexity for the Breadth-First Search is _O(V + E)_, where _V_ is the number of vertices in the graph, and _E_ is the number of edges in the graph. Each vertex is visited once, and each edge is visited at most twice, which is where the meaning of _V_ and _E_ in the time complexity come from.

In Big O Notation, the time complexity for the Depth-First Search is _O(V + E)_, which is the same as the time complexity for the Breadth-First Search.
