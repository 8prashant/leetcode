class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(),v.end());
        int m=v[v.size()-1];
        int ans=1;
        vector<int>val(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                val[i]+=val[i-1];
            }
            if(nums[i]==m){
                ans=max(ans,val[i]);
            }
        }
        return ans;
    }
};