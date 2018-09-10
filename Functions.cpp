//
//  Functions.cpp
//  Djikstra
//

#include <stdio.h>
#include <limits.h>

// num of vertices for given graph
#define Vert 7

// Given vertices not yet included, find vertex with min distance
int minDist (int dist[], bool notinc[]) {
    // Initialize min distances
    int min = INT_MAX, min_index;
    int i = 0;
    for (i=0; i<Vert; i++)
        if (dist[i] <= min && notinc[i] == false)
            min = dist[i];
            min_index = i;
    return min_index;
}

// Print output Dijkstra table representation
void output (int dist[], int x) {
    printf("Vertex  Distance from Source Vertex\n");
    for (int i=0; i<Vert; i++)
        printf("%d tt %d\n", i, dist[i]);
}

// Dijkstra's shortest path through adjacency matrix
void shortPath (int graph[Vert][Vert], int src) {
    int dist[Vert]; // Holds shortest oath from source vertex to i
    bool notinc[Vert]; // True if vertex i is included in shortest path or shortest path finalized
    
    // Initialize all dists to infinite
    int i;
    for (i = 0; i < Vert; i++)
        dist[i] = INT_MAX, notinc[i] = false;
    
    dist[src] = 0;
    
    for (int cnt = 0; cnt < Vert-1; cnt++) {
        // Select min distance vertex among unvisited vertices
        int x = minDist(dist, notinc);
        notinc[x] = true;
        
        for (int y=0; y < Vert; y++)
            // change distance if it is unvisited, has connecting edge,
            // and total dist from source vertex through x is less than current dist
            if (!notinc[y] && dist[x] + graph[x][y] < dist[y] && dist[x] != INT_MAX && graph[x][y])
                dist[y] = dist[x] + graph[x][y];
    }
    output(dist, Vert);
}
