class Solution {
public:
    vector<vector<int>>dp;
    int check(int i,int j,vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int l=i;l<=j;l++){
            ans=max(ans,
                ((nums[i-1]*nums[l]*nums[j+1])+check(i,l-1,nums)+check(l+1,j,nums))
            );
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        return check(1,nums.size()-2,nums);
    }
};