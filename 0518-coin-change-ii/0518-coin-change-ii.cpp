class Solution {
public:
int dp[305][5005];
int fn(int k,vector<int>&a,int i){
    if(i<=0||k<0)return 0;
    if(dp[i][k]!=-1)return dp[i][k];
    if(k==0)return 1;
    int p=fn(k-a[i-1],a,i);
    int q=fn(k,a,i-1);
    return dp[i][k]=p+q;
}
    int change(int k, vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        return fn(k,a,a.size());
    }
};