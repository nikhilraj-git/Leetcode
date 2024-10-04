class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)continue;
                int up=INT_MAX;
                int right=INT_MAX;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    right=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,right);
            }
        }
        return dp[n-1][m-1];
    }
};