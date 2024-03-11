class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        string st1;
        for(auto x:order){
            if(m.find(x)!=m.end()){
                // st1+=x;
                // m[x]--;
                // if(m[x]==0){
                //     m.erase(x);
                // }
                for(int i=0;i<m[x];i++){
                    st1+=x;
                }
                m.erase(x);
            }
        }
        for(auto x:m){
            for(int i=0;i<x.second;i++){
                st1+=x.first;
            }
        }
        return st1;    
    }
};