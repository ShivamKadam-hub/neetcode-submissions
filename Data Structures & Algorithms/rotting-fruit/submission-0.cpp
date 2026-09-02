class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    cnt++;
            }
        }
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int time = 0;
        while (!q.empty() && cnt > 0) {
            int s = q.size();
            while (s--) {
                auto [i, j] = q.front();
                q.pop();
               
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                        q.push({ni, nj});
                        cnt--;
                        grid[ni][nj] = 2;
                    }
                }
            }
            time++;
        }

        return (cnt > 0 ? -1 : time);
    }
};
