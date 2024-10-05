class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
           int n=matrix.size();
           int m=matrix[0].size();
           vector<vector<int>> dp(n,vector<int>(m,0));
           for(int i=0;i<n;i++)
           {
            for(int j=0;j<m;j++)
            {
                if(i==0){
                    dp[i][j]=matrix[i][j];
                    continue;
                }
                int up=INT_MAX;
                int right=INT_MAX;
                int left=INT_MAX;
                
                if(j>0)
                    right=dp[i-1][j-1];
                if(j<m-1)
                    left=dp[i-1][j+1];
                if(i>0)
                    up=dp[i-1][j];
                dp[i][j]=min(up,min(right,left))+matrix[i][j];

            }
           }
           int ans=INT_MAX;
           for(int i=0;i<m;i++)
                ans=min(ans,dp[n-1][i]);
            return ans;
    }
};