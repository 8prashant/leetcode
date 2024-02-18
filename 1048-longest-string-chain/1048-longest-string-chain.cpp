bool compare(const string& a,  const string& b){
    return a.size()<b.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> m;
        int ans=0;
        for(auto x:words){
            int ans=0;
            m[x]=1;
            for(int i=0;i<x.size();i++){
                string s1=x.substr(0,i)+x.substr(i+1,x.size());
                if(m.find(s1)!=m.end()){
                    m[x]=max(m[x],1+m[s1]);
                }
            }
            // ans=max(ans,m[x]);
        }
        for(auto x:m){
            ans=max(ans,x.second);
        }
        return ans;
    }
};