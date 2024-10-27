class Solution {
public:
    bool solve(vector<int> nums,int th,int div)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]+div-1)/div;

        }

        if(sum>th)return false;
        else return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s =1,e=INT_MAX;
        int ans=0;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(solve(nums,threshold,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};