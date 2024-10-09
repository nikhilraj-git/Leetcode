class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                   
                    if (i == 0 || j == 0 || i == n-1 || j == m-1) { 
                        q.push({i, j});
                        vis[i][j] = 1; 
                    }
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] == 1) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1; 
                
                }
            }
        }

       int count=0;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1 && vis[i][j]==0)
                count++;
        }
       }
       return count;
    }
};
