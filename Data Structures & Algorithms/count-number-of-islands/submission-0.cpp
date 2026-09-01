class Solution {
public:
    int dx[4] = {1 , 0  , -1 , 0};
    int dy[4] = {0 , -1 , 0 , 1};
    void bfs(int i , int j , int n , int m ,vector<vector<char>>& grid,vector<vector<int>>& vis){
        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];


            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny] == '1'){
                vis[nx][ny] = 1;
                bfs(nx , ny , n , m , grid , vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));

        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    vis[i][j] = 1;
                    bfs(i , j , n , m , grid , vis);
                }
            }
        }
        return cnt;

    }
};
