class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Find the largest index ind such that nums[ind] < nums[ind + 1]
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no such index exists, the permutation is the last permutation
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return; // Return after reversing to avoid further processing
        }

        // Find the largest index j greater than ind such that nums[ind] < nums[j]
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Reverse the sequence from ind + 1 to the end
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
