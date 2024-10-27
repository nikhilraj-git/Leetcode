class Solution {
public:
    bool solve(vector<int> piles,int h,int maxSpeed)
    {
        int hour=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
           hour +=(piles[i]+maxSpeed-1)/maxSpeed;
        } 
            if(hour>h)return false;
            else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=-1;
        int s=1,e=INT_MAX;
        while(s<=e)
        {
            int mid =s+(e-s)/2;
            if(solve(piles,h,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;
    }
};