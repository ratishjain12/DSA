//bfs 

/* Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. 
   Check whether the graph is bipartite or not.  
   you can color nodes with two colors
   A graph is bipartite if no two adjacent vertices have the same color
*/
bool bfs(int node, vector<int>adj[],vector<int>&color){
    color[node] = 0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    // Code here
    vector<int>color(V,-1);
    for(int i = 0;i<V;i++){
        if(color[i] == -1){
            if(bfs(i,adj,color) == false){
                return false;
            }
        }
    }
    return true;
    
}

//dfs 
bool dfs(int node,int currentColor,vector<int>adj[],vector<int>&color){
    color[node] = currentColor;
    for(auto it : adj[node]){
        if(color[it] == -1){
            if(dfs(it,!currentColor,adj,color) == false){
                return false;
            }
        }else if(color[it] == currentColor){
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
    // Code here
    vector<int>color(V,-1);
    for(int i = 0;i<V;i++){
        if(color[i] == -1){
            if(dfs(i,0,adj,color) == false){
                return false;
            }
        }
    }
    return true;
    
}