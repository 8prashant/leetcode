class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int len=0;
        int i=1;
        while(i<s.size()){
            if(s[i]==s[len]){
                lps[i]=len+1;
                i++;
                len++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        int ans=lps[n-1];
        string a=s.substr(0,ans);
        return a;
    }
};