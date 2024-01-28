// memoization with dp
class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(int index,int target,vector<int>& nums){
        if(target==0){
            return true;
        }
        if(index==0){
            return (nums[0]==target);
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool notinc=dfs(index-1,target,nums);
        bool inc=false;
        if(nums[index]<=target){
            inc=dfs(index-1,target-nums[index],nums);
        }
        dp[index][target] = notinc || inc ;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int ts=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            ts+=nums[i];
        }
        if(ts%2!=0){
            return false;
        }
        int k=ts/2;
        dp.assign(n,vector<int>(k+1,-1));
        return dfs(n-1,k,nums);
    }
};