class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            xor1=xor1^nums[i];
        }
    
        return xor1;
    }

};