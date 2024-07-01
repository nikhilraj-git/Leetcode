class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int mini = nums.size()/3+1;
        for(int  i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;

            if(mp[nums[i]]==mini)ans.push_back(nums[i]);
            if(ans.size()==2)return ans;
            
        }
        return ans;
    }
};