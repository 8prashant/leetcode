//TABULATION
class Solution {
public:
    // vector<vector<int>> dp;
    // bool dfs(int index,int target,vector<int>& nums){
    //     if(target==0){
    //         return true;
    //     }
    //     if(index==0){
    //         return (nums[0]==target);
    //     }
    //     if(dp[index][target]!=-1){
    //         return dp[index][target];
    //     }
    //     bool notinc=dfs(index-1,target,nums);
    //     bool inc=false;
    //     if(nums[index]<=target){
    //         inc=dfs(index-1,target-nums[index],nums);
    //     }
    //     dp[index][target] = notinc || inc ;
    //     return dp[index][target];
    // }
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
        // dp.assign(n,vector<int>(k+1,-1));
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]==true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                bool notinc=dp[i-1][j];
                bool inc=false;
                if(nums[i]<=j){
                    inc=dp[i-1][j-nums[i]];
                }
                dp[i][j]=notinc || inc;
            }
        }
        return dp[n-1][k];
        // return dfs(n-1,k,nums);
    }
};