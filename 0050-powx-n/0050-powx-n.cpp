class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Cast n to long long to avoid overflow
        
        if (N < 0) {
            N = -N;  // Safely negate the value
            x = 1 / x;
        }
        
        double ans = 1;
        while (N > 0) {
            if (N & 1) {
                ans = ans * x;
            }
            x = x * x;
            N >>= 1;  // Right shift N by 1 bit
        }
        
        return ans;
    }
};
