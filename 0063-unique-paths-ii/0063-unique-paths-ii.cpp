class Solution {
public:
    int boobies(vector<vector<int>>& v, int r, int d, int m, int n,vector<vector<int>>&dp){
        if(r==m && d==n){
            return v[m][n]==1?0:1;
        }
        if(r>m || d>n || v[r][d]==1){
            return 0;
        }
        if(dp[r][d]!=-1){
            return dp[r][d];
        }
        int ans=boobies(v,r+1,d,m,n,dp)+boobies(v,r,d+1,m,n,dp);
        dp[r][d]=ans;
        return dp[r][d];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m=og.size();
        int n=og[0].size();
        vector<vector<int>>v(m,vector<int>(n,-1));
        return boobies(og,0,0,m-1,n-1,v);
    }
};