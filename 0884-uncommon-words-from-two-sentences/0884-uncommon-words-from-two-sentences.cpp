class Solution {
public:
    unordered_map<string,int>m;
    void check(string s1){
        vector<string>v;
        string a="";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                m[a]++;
                a="";
            }
            else{
                a+=s1[i];
            }
        }
        if(a.size()>0){
            m[a]++;
        }
        return;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        check(s1);
        check(s2);
        vector<string>ans;
        for(auto x:m){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};