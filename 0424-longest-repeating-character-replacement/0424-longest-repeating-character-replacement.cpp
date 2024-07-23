class Solution {
public:
    unordered_map<int,int>m;
    int characterReplacement(string s, int k) {
       int i=0,j=0;
       int ma=1;
       int ans=0;
       while(j<s.size()){
        m[s[j]]++;
        ma=max(ma,m[s[j]]);
        while((j-i+1)-ma>k){
            m[s[i]]--;
            i++;
        }
        ans=max(ans,(j-i+1));
        j++;
       }
       return ans;
    }
};