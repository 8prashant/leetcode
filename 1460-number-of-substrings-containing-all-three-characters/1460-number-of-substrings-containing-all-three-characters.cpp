class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>m;
        while(j<s.size()){
            m[s[j]]++;
            while(m.size()>=3){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                ans+=(s.size()-j);
                i++;
            }
            j++;
        }
        return ans;
    }
};