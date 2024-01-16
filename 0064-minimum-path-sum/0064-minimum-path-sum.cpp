class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,int m,int n,vector<vector<int>>& gd){
        if(i==m-1 && j==n-1){
            return gd[i][j];
        }
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=gd[i][j];
        int r=dfs(i,j+1,m,n,gd);
        int d=dfs(i+1,j,m,n,gd);
        ans+=min(r,d);
        dp[i][j]=ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& gd) {
        int m=gd.size(),n=gd[0].size();
        dp.assign(m,vector<int>(n,-1));
        int ans=dfs(0,0,m,n,gd);
        return ans;
    }
};