class Solution {
public:
    string shortestPalindrome(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        str=s+"#"+str;
        int n=str.size();
        vector<int>lps(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(str[i]==str[len]){
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
        int l=lps[n-1];
        return str.substr(s.size()+1,(s.size()-l))+s;
    }
};