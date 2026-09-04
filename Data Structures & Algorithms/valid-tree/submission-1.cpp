class Solution {
public:
    bool bfs(int node ,vector<int>& vis , vector<vector<int>>adj){
        queue<pair<int,int>> q;
        q.push({node , -1});
        vis[node] = 1;

        while(!q.empty()){
            auto [src, parent] = q.front(); q.pop();
            for(auto it : adj[src]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it , src});
                }
                else if(it!=parent) return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        if(bfs(0 , vis , adj)) return false;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
               return false;
            } 
        }

        return true;
    }
};
