Problem

Given a weighted, directed graph represented by an adjacency matrix, find the shortest path from a start vertex to a target vertex using Dijkstra's algorithm.
Solution

The solution is implemented in C++. The program includes a Graph class that uses a 2D array to represent the graph and provides a method path_finder to find the shortest path from a start vertex to a target vertex.

The path_finder method takes two input parameters: a start_vertex and a target_vertex. The method creates 3 vectors dist, prev and visited to store the distance from the start vertex to each vertex, the previous vertex in the shortest path and if a vertex has been visited or not.

It starts by initializing the distance from the start vertex to itself as 0 and all other distances as the maximum value of std::int16_t. It also initializes the prev vector with -1 for all vertices, and the visited vector with false for all vertices.

The method then enters a loop that runs for n iterations, where n is the number of vertices in the graph. In each iteration, it selects the vertex with the minimum distance from the start vertex that has not been visited yet, and marks it as visited. It then iterates through all vertices and updates the distance and previous vertex if the current path is shorter than the previously recorded path.

Finally, it prints the shortest path, by tracing back the path using the prev vector.
