class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod1=nums[0];
        int prod2=nums[0];
        int ans=nums[0];

        for(int i=1;i<n;i++)
        {
            int temp=max(nums[i],max(prod1*nums[i],prod2*nums[i]));
            prod2=min(nums[i],min(prod1*nums[i],prod2*nums[i]));
            prod1=temp;
            ans=max(ans,prod1);
        }
        return ans;
    }
};