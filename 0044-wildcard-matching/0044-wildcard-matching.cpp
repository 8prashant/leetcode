class Solution {
public:
    vector<vector<int>>dp;
    bool check(string &s, string &p,int i,int j){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && p[j]=='*'){
            return check(s,p,i,j-1);
        }
        if(i<0 || j<0){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j]==1?true:false;
        }
        if(s[i]==p[j]){
            return dp[i][j]=check(s,p,i-1,j-1)==true?1:0;
        }
        else if(p[j]=='?'){
            return dp[i][j]=check(s,p,i-1,j-1)==true?1:0;
        }
        else if(p[j]=='*'){
            return dp[i][j]=(
                check(s,p,i-1,j) ||
                check(s,p,i,j-1) ||
                check(s,p,i-1,j-1)
            )==true?1:0;
        }
        dp[i][j]=0;
        return false;
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size(),vector<int>(p.size(),-1));
        return check(s,p,s.size()-1,p.size()-1);
    }
};