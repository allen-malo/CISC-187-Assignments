
[Video Link](https://youtu.be/75vRsFycR8U)

**1. Explain with the help of an example "Why Dijkstra's algorithm fails on negative weights".**

Before we go over why Dijkstra's algorithm fails on negative weights, let's go over what exactly this algorithm is.

Dijkstra's algorithm first initializes all the distances from each vertex to infinity, all of their predecessors to null, and enqueues all vertices into a queue of unvisited vertices. The starting vertex is then initialized with a distance of 0 (since this is its own vertex). We'll then move onto the adjacent vertices, and if a shorter path from the start vertex to this vertex is found, then the vertex's distance and predecessor pointer are updated to reflect this. The important thing to note here is that once the shortest path to a vertex is found, it is finalized and **never revisted** after. This assumption only works when all edge weights are **non-negative.** However, in this hypothetical scenario, there are edges with negative weights, so let's see why Dijkstra's algorithm fails now.

Another question that you might be asking yourself: Why would we use negative weights if we know Dijkstra's algorithm doesn't work here? The answer to this depends on what the graph represents. For example, negative weight could represent profit, where choosing this edge grants a reward/more money.

Now that we've established the foundation of why this question arises, let's go over why Dijkstra's algorithm fails with negative weights.

We'll start with a simple graph here:

<img width="1077" height="828" alt="GraphLab11" src="https://github.com/user-attachments/assets/85d0c392-505d-4664-ae10-bc6c9dfbba2c" />

From this graph, we can see that the following paths and their weights:

A -> C: 2<br>
A -> B: 3<br>
B -> C: -12<br>

Given these paths, we can immediately tell that the shortest path to go from A -> C is actually going from A -> B -> C, which would give a total weight of 3 + -12 = -9 vs going directly from A -> C, which has a weight of 2. However, Dijkstra's algorithm wouldn't be able to figure this out for **one major flaw**: it locks in the path and doesn't allow for overwrites. That means, in our example here, Dijkstra's algorithm first sees that the path from A -> C has a weight of 2, vs the path from A -> B with a weight of 3, and immediately assumes that A -> C is the shortest path. Then, Dijkstra's algorithm goes on to see the weight of B -> C, which is -12. Dijkstra's algorithm now knows that another possible path from A -> C is A -> B -> C, which has a weight of -9 (less than the weight of the path locked in). However, the original path was already locked in, and thus this path cannot be recognized as the more optimal path, therefore causing Dijkstra's algorithm to fail.
