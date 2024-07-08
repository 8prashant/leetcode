class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0,j=0;
        unordered_map<char,int>m;
        while(j<s.size()){
            m[s[j]]++;
            while(m[s[j]]>1){
                m[s[i]]--;
                i++;
            }
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};