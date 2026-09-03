class Solution {
public:
    void dfs(int i , int j ,int val ,vector<vector<int>>& vis ,vector<vector<int>>& h ){
        int n = h.size() , m  = h[0].size();

        if(i<0 || i>=n || j<0 || j>=m || h[i][j]<val || vis[i][j]) return;

        vis[i][j] = 1;

        dfs(i+1 , j , h[i][j] , vis , h);
        dfs(i-1 , j , h[i][j] , vis , h);
        dfs(i , j+1 , h[i][j] , vis , h);
        dfs(i , j-1 , h[i][j] , vis , h);

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size() , m  = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> p(n , vector<int>(m,0));
        vector<vector<int>> a(n , vector<int>(m,0));
        

        for(int i = 0;i<n;i++){
            dfs(i , 0 ,-1, p ,heights);
            dfs(i , m-1 ,-1, a ,heights);
        }
        for(int j = 0;j<m;j++){
            dfs(0 , j ,-1, p ,heights);
            dfs(n-1,j ,-1, a ,heights);
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(a[i][j] && p[i][j]) ans.push_back({i,j});
            }
        }
        return ans;

    }
};
