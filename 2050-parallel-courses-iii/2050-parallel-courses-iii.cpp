class Solution {
public:
    vector<int>dp;
    int check(int x,vector<vector<int>>&cc,vector<vector<int>>&cp,vector<int>& t){
        if(cp[x].size()==0){
            return t[x-1];
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans=INT_MIN;
        for(auto y:cp[x]){
            ans=max(ans,t[x-1]+check(y,cc,cp,t));
        }
        return dp[x]=ans;
    }
    int minimumTime(int n, vector<vector<int>>& re, vector<int>& t) {
        vector<vector<int>>cc(n+1),cp(n+1);
        for(auto x:re){
            cc[x[0]].push_back(x[1]);
            cp[x[1]].push_back(x[0]);
        }
        dp.resize(n+1,-1);
        queue<int>q;
        for(int i=1;i<cc.size();i++){
            if(cc[i].size()==0){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            int res=check(a,cc,cp,t);
            ans=max(ans,res);
        }
        return ans;
    }
};