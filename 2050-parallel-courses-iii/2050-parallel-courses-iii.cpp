class Solution {
public:
    vector<int>dp;
    int check(int n,vector<vector<int>>&cp,vector<int>& t){
        if(dp[n]!=-1){
            return dp[n];
        }
        int cost=t[n-1];
        int ma=0;
        for(auto x:cp[n]){
            ma=max(ma,check(x,cp,t));
        }
        return dp[n]=cost+ma;
    }
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& t) {
        vector<vector<int>>cc(n+1);
        vector<vector<int>>cp(n+1);
        dp.resize(n+1,-1);
        int ans=0;
        for(auto x:r){
            cc[x[0]].push_back(x[1]);
            cp[x[1]].push_back(x[0]);
        }
        for(int i=1;i<=n;i++){
            if(cc[i].size()==0){
                int a=check(i,cp,t);
                ans=max(ans,a);
            }
        }
        return ans;
    }
};