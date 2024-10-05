class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int bottom = INT_MAX, diagonal = INT_MAX;
                if (j <= i - 1) {
                    bottom = dp[i-1][j];
                }
                if (j > 0) {
                    diagonal = dp[i-1][j-1];
                }
                dp[i][j] = triangle[i][j] + min(bottom, diagonal);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};
