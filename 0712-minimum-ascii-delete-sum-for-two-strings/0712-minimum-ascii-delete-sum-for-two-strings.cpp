class Solution {
public:
    int check(string &s1, string &s2,int m,int n,vector<vector<int>>&v){
        if (m == 0) {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += s2[i];
            return sum;
        } else if (n == 0) {
            int sum = 0;
            for (int i = 0; i < m; i++)
                sum += s1[i];
            return sum;
        }
        if(v[m][n]!=-1){
            return v[m][n];
        }
        int ans=0;
        if(s1[m-1]==s2[n-1]){
            v[m][n]=check(s1,s2,m-1,n-1,v);
            return v[m][n];
        }
        else{
            ans=min(
                (ans+s2[n-1]+check(s1,s2,m,n-1,v)),
                (ans+s1[m-1]+check(s1,s2,m-1,n,v))
            );
        }   
        v[m][n]=ans;
        return v[m][n];
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>v(s1.size()+1,vector<int>(s2.size()+1,-1));
        int m=s1.size();
        int n=s2.size();
        return check(s1,s2,m,n,v);
        
    }
};