class Solution {
public:
    vector<vector<int>>dp;
    bool res(int x,int t,vector<int>&v){
        if(t==0){
            return true;
        }
        if(x<0){
            return false;
        }
        if(dp[x][t]!=-1){
            return dp[x][t];
        }
        bool notinc=res(x-1,t,v);
        bool inc=false;
        if(t>=v[x]){
            inc=res(x-1,t-v[x],v);
        }
        return dp[x][t]=notinc || inc?1:0;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        dp.resize(nums.size(),vector<int>(target+1,-1));
        return res(nums.size()-1,target,nums);
    }
};