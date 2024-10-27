class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n =nums.size();
        int s =0,e=n-1;
        while(s<=e)
        {
            int mid =s+(e-s)/2;
            if(target==nums[mid])return true;
            if(nums[s]==nums[mid] && nums[mid]==nums[e])
            {
                s=s+1;
                e=e-1;
                continue;
            }
            if(nums[s]<=nums[mid])
            {
                if(nums[s]<=target && nums[mid]>=target)
                {
                    e=mid-1;
                }
                else 
                {
                    s=mid+1;
                }
            }
            else
            {
                if(nums[mid]<=target && nums[e]>=target)
                {
                    s=mid+1;
                }
                else 
                {
                    e=mid-1;
                }
            }
        }
        return false;
    }
};