//find shortest distance to all vertex from source vertex S
//we use min heap to store pair of {dist,node}
//do bfs for each node and keep track of shortest distance using dist vector

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(V,1e9);
    dist[S] = 0;
    pq.push({dist[S],S});
    while(!pq.empty()){
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edgeWeight = it[1];
            if(edgeWeight + distance < dist[adjNode]){
                dist[adjNode] = edgeWeight + distance;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}