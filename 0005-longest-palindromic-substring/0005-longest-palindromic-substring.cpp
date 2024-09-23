class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int ref=0;
        for(int i=0;i<s.size();i++){
            //ODD PALIN
            int l=i,m=i;
            while(l>=0 && m<s.size() && s[l]==s[m]){
                if((m-l+1)>ref){
                    ans=s.substr(l,m-l+1);
                    ref=(m-l+1);
                }
                l--;
                m++;
            }
            //EVEN PLAIN
            l=i,m=i+1;
            while(l>=0 && m<s.size() && s[l]==s[m]){
                if((m-l+1)>ref){
                    ans=s.substr(l,m-l+1);
                    ref=(m-l+1);
                }
                l--;
                m++;
            }
        }
        return ans;
    }
};