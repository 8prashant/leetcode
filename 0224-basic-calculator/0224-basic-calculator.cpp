//WORST CASE TC-> O(N^2)
class Solution {
public:
    int check(string s,int i,int j){
        vector<int>v;
        int l=i;
        int p=0;
        int o=0;
        while(l<=j){
            if(s[l]>='0' && s[l]<='9'){
                string st1="";
                while(s[l]>='0' && s[l]<='9' && l<=j){
                    st1+=s[l];
                    l++;
                    i++;
                }
                int n=stoi(st1);
                if(p==-1){
                    v.push_back(-n);
                    p=0;
                }
                else{
                    v.push_back(n);
                }
            }
            else if(s[l]=='-'){
                p=-1;
                l++;
                i=l;
            }
            else if(s[l]=='('){
                o++;
                l++;
                while(o!=0 && l<=j){
                    if(s[l]=='('){
                        o++;
                    }
                    if(s[l]==')'){
                        o--;
                    }
                    l++;
                }
                int n=check(s,i+1,l-2);
                if(p==-1){
                    v.push_back(-n);
                    p=0;
                }
                else{
                    v.push_back(n);
                }
                i=l;
            }
            else{
                l++;
                i=l;
            }
        }
        int ans=0;
        for(auto x:v){
            ans+=x;
        }
        return ans;
    }
    int calculate(string s) {
        return check(s,0,s.size()-1);
    }
};