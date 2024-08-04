class Solution {
public:
    vector<vector<int>>dp;
    int check(int i,int j,vector<int>& nums){
        if(j-i<=1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MIN;
        for(int l=i+1;l<j;l++){
            ans=max(ans,(
                (nums[i]*nums[l]*nums[j])+check(i,l,nums)+check(l,j,nums)
            ));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        dp.resize(n,vector<int>(n,-1));
        return check(0,n-1,nums);
    }
};