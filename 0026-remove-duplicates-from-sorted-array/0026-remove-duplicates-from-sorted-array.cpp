class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int j=1;j<n;j++){
            if(arr[ans]!=arr[j])
            {
                ans++;
                arr[ans]=arr[j];
            }
        }
        return ans+1;
        
    }
};