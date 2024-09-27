class Node{
    public:
    unordered_map<char,pair<int,Node*>>m;
    bool end=false;
};
class trie{
    private:
    Node* root;
    public:
    trie(){
        root=new Node{};
    }
    void insert(string s){
        Node* curr=root;
        for(auto x:s){
            if(curr->m.find(x)==curr->m.end()){
                curr->m[x].second=new Node{};
            }
            curr->m[x].first++;
            curr->end=false;
            curr=curr->m[x].second;
        }
        curr->end=true;
    }
    int check(int n){
        Node* curr=root;
        int ans=0;
        while(curr->end!=true){
            if(curr->m.size()==1 && curr->m.begin()->second.first==n){
                ans++;
                curr=curr->m.begin()->second.second;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        trie ob1;
        for(auto x:strs){
            ob1.insert(x);
        }
        int l=ob1.check(strs.size());
        return strs[0].substr(0,l);
    }
};