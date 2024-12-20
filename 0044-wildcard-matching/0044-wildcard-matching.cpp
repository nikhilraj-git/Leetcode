class Solution {
public:
    bool isAllStar(string p, int i) {
        for (int j = 1; j <= i; j++) {
            if (p[j - 1] != '*') return false;
        }
        return true;
    }

    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true; 
        for (int i = 1; i <= n; i++) {
            dp[i][0] = isAllStar(p, i);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];  
                } else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};
