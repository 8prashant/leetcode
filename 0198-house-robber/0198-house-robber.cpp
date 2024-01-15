class Solution {
public:
    vector<int> dp;
    int dfs(int i,int n,vector<int>& nums){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=nums[i];
        int res=0;
        for(int j=i+2;j<n;j++){
            int res1=dfs(j,n,nums);
            res=max(res,res1);
        }
        ans+=res;
        dp[i]=ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int res=dfs(i,n,nums);
            ans=max(ans,res);
        };
        return ans;
    }
};