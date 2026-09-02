
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        DisjointSet dsu(n*m);
        bool posi = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1){
                    posi = true;
                    int id = i*m + j;
                    if(i<n-1 && grid[i+1][j])dsu.unionBySize(id , (i+1)*m + j);
                    if(j<m-1 && grid[i][j+1])dsu.unionBySize(id , i*m + j + 1);
                }
            }
        }
        int maxa = INT_MIN;
        for(auto it : dsu.size){
            maxa = max(maxa , it);
        }

        return posi==true?maxa:0;
    }
};
