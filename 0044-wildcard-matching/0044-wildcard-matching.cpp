class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(int i, int j, string &s, string &p){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && p[j]=='*'){
            return true && dfs(i,j-1,s,p);
        }
        if(i<0 || j<0){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]!='*' && p[j]!='?'){
            return dp[i][j]=s[i]==p[j]? dfs(i-1,j-1,s,p):false;
        }
        else if(p[j]=='?'){
            return dp[i][j]=dfs(i-1,j-1,s,p);
        }
        return dp[i][j]=dfs(i-1,j-1,s,p) || dfs(i-1,j,s,p) || dfs(i,j-1,s,p);
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        dp.assign(n,vector<int>(m,-1));
        return dfs(n-1,m-1,s,p);
    }
};