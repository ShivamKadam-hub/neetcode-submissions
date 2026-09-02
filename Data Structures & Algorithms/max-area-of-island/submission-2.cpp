
class DisjointSet{
    public:
        vector<int> size,parent;
        DisjointSet(int n){
            size.resize(n+1);
            parent.resize(n+1);
            for(int i =0;i<=n;i++){
                size[i] = 1;
                parent[i] = i;
            }
        }

        int findUPar(int n){
            if(n == parent[n]) return n;
            return parent[n] = findUPar(parent[n]);
        }

        void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution {
public:
    int dx[4] = {1 , 0 , -1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    int bfs(int i , int j ,vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size();

        queue<pair<int,int>>  q;
        q.push({i , j});
        grid[i][j] = 0;
        int res = 1;
        while(!q.empty()){
            auto [r , c] = q.front(); q.pop();
            for(int k = 0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc] = 0;
                    q.push({nr , nc});
                    res++;
                }
            }
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int area = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    area = max(area , bfs(i , j , grid));
                }
            }
        }
       return area;
    }
};
