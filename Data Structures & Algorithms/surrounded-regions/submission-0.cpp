class Solution {
   public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == 'X'|| vis[i][j]) return;

        vis[i][j] = 1;

        dfs(i + 1, j, vis, board);
        dfs(i - 1, j, vis, board);
        dfs(i, j + 1, vis, board);
        dfs(i, j - 1, vis, board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if(board[i][0]=='O' && !vis[i][0])dfs(i, 0,vis,board);
            if(board[i][m-1]=='O' && !vis[i][m-1])dfs(i, m-1,vis,board);
        }
        for (int j = 0; j < m; j++) {
            if(board[0][j]=='O' && !vis[0][j])dfs(0, j,vis,board);
            if(board[n-1][j]=='O'&& !vis[n-1][j])dfs(n-1, j,vis,board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
