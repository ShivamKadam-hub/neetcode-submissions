class Solution {
public:
    bool dfs(int node , vector<vector<int>>& adj , vector<int>& vis , vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it , adj , vis , pathVis)) return true;;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        //constructing an adjacency matrix;
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //creating visited and pathvisited arrays for tracking the cycle

        vector<int> pathVis(n), vis(n);

        //using dfs for checking cyclic nature in the graph(directed)

        for(int i = 0;i<n;i++){
         if(dfs(i , adj , vis , pathVis)) return false;   
        }

        return true;
    }
};
