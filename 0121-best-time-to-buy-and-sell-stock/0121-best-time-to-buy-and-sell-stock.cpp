class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> pre(n);
    pre[0]=prices[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=min(prices[i],pre[i-1]);
    }
    int ans=0;
    for(int i=n-1;i>0;i--)
    {
        int diff=prices[i]-pre[i-1];
        ans=max(ans,diff);
    }
    return ans;
       
    }
};