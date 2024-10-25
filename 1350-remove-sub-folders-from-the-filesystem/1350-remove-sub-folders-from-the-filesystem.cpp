bool comparator(string a,string b){
    return a.size()<b.size();
}
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end(),comparator);
        for(auto x:folder){
            cout<<x<<" ";
        }
        set<string>m;
        vector<string>ans;
        for(auto x:folder){
          bool ref=true;
          for(int i=1;i<x.size();i++){
            if(i!=x.size()-1 && x[i+1]!='/'){
                continue;
            }
            string a;
            a=x.substr(0,i+1);
            if(m.find(a)!=m.end()){
                ref=false;
                break;
            }
          }

          if(ref==true){
            ans.push_back(x);
          }
          m.insert(x);  
        }
        return ans;
    }
};