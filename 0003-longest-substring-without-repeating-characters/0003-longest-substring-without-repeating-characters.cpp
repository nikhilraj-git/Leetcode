class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int ans=0;
        int left=0;
        int right=0;
        int n=s.length();
        while(right<n)
        {
            if(us.find(s[right])==us.end())
            {
                us.insert(s[right]);
                ans=max(ans,right-left+1);
                right++;
            }
            else 
            {
                us.erase(s[left]);
                left++;
            }
        }
        return ans;

    }
};