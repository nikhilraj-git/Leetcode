class Solution {
public:
    int uniquePaths(int n, int m) {
     vector<vector<int>> dp(n,vector<int>(m,0));
     dp[0][0]=1;
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
        if(i==0 && j==0)continue;
            int up=0,right=0;
            if(i>0)
                up=dp[i-1][j];
            if(j>0)
                right=dp[i][j-1];

            dp[i][j]=up+right;
        }

     }   
     return dp[n-1][m-1];
    }
};