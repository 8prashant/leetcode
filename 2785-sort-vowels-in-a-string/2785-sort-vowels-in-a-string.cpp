class Solution {
public:
    string sortVowels(string s) {
        vector<int>p;
        vector<char>v;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u'){
                p.push_back(i);
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            s[p[i]]=v[i];
        }
        return s;
    }
};