// Find shortest path from source to all the vertex of the graph
// if graph contains negative weight cycle return -1
// Graph contains negative edges so bellman ford algorithm is used


// Bellman ford algorithm
// states relax all n nodes n-1 times to find shortest path from source to all the vertex of the graph
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // Code here
    vector<int>dist(V,1e8);
    dist[S] = 0;
    // N-1 relaxations of all the edge
    for(int i = 0;i<V-1;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    
    // Nth relaxation to check for negative weight cycle
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    
    return dist;
}



// program to check for negative weight cycle
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    // Code here
    if(edges.size() == 0) return 0;
    vector<int>dist(n,1e8);
    int s = edges[0][0]; // taking first node as source
    dist[s] = 0;
    // N-1 relaxations of all the edge
    for(int i = 0;i<n-1;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

// Nth relaxation to check for negative weight cycle
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return 1;
        }
    }

    return 0;
}