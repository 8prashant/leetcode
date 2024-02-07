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
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int res=dfs(word1,word2,n-1,m-1,dp);
        return (n-res)+(m-res);
    }
};