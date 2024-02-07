class Solution {
public:
int dfs(string &origi,string &rev,int index1 , int index2,vector<vector<int>> &dp){
    if(index1<0 || index2<0){
        return 0;
    }
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
    if(origi[index1]==rev[index2]){
        return dp[index1][index2]=1+dfs(origi,rev,index1-1,index2-1,dp);
    }
    int left=dfs(origi,rev,index1-1,index2,dp);
    int right=dfs(origi,rev,index1,index2-1,dp);
    return dp[index1][index2]=max(left,right);
}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string origi=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int res=dfs(origi,s,n-1,n-1,dp);
        return res;
    }
};