class Solution {
public:
    set<string>s;
    vector<int>dp;
    int check(int i,int n,string &st){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        string a="";
        for(int l=i;l<n;l++){
            a+=st[l];
            if(s.find(a)!=s.end()){
                int res=check(l+1,n,st);
                ans=min(ans,res);
            }
        }
        int res=1+check(i+1,n,st);
        ans=min(ans,res);
        return dp[i]=ans;
    }
    int minExtraChar(string st, vector<string>& dictionary) {
        for(auto x:dictionary){
            s.insert(x);
        }
        dp.resize(st.size(),-1);
        return check(0,st.size(),st);

    }
};