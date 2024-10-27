class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=-1,right=-1;
     left = BinarySearch(nums,target,true);
      right=BinarySearch(nums,target,false);
        return {left,right};

    }
    int BinarySearch(vector<int> &nums,int target,bool isLeft)
    {
        int s=0,e=nums.size()-1;
        int ans=-1;
        while(s<=e)
        {
            int mid =s+(e-s)/2;
            if(target>nums[mid])
            {
                s=mid+1;
            }
            else if(target<nums[mid])
            {
                e = mid-1;
            }
            else 
            {
                    ans=mid;
                if(isLeft)
                {
                    e=mid-1;
                }
                else 
                {
                    s=mid+1;
                    
                }
            }
        }
        return ans;
    }
};