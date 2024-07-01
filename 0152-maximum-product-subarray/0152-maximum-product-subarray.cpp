class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(suffix==0)suffix=1;
            if(prefix==0)prefix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-1-i];
            ans=max(ans,max(suffix,prefix));
        }
        return ans;
    }
};