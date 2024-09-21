/*
Brut-Force
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>v;
        for(int i=1;i<=n;i++){
            string a=to_string(i);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(auto x:v){
            int a=stoi(x);
            ans.push_back(a);
        }
        return ans;
    }
};
*/
class Solution {
public:
    vector<int>ans;
    void check(string a,int &n){
        int x=stoi(a);
        if(x<=n){
            ans.push_back(x);
        }
        else{
            return;
        }
        for(char i='0';i<='9';i++){
            string b=a+i;
            check(b,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            if(n>=i){
                string a=to_string(i);
                check(a,n);
            }
        }
        return ans;
    }
};