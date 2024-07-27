class Solution {
public:
    bool check(int i, int j,string &s){
        if(i==j){
            return s[i]=='t'?true:false;
        }
        int l=i+2,r=i+2;
        bool ans;
        int count=0;
        if(s[i]=='&'){
            ans=true;
            while(r<=j){
                if((s[r]==',' || r==j)&& count==0){
                    ans&=check(l,r-1,s);
                    l=r+1;
                }
                if(s[r]=='('){
                    count++;
                }
                else if(s[r]==')'){
                    count--;
                }
                r++;
            }
        }
        else if(s[i]=='!'){
           ans=check(i+2,j-1,s)==true?false:true;
        }
        else{
            ans=false;
            while(r<=j){
                if((s[r]==',' || r==j)&& count==0){
                    ans|=check(l,r-1,s);
                    l=r+1;
                }
                if(s[r]=='('){
                    count++;
                }
                else if(s[r]==')'){
                    count--;
                }
                r++;
            }
        }
        return ans;
    }
    bool parseBoolExpr(string ex) {
        return check(0,ex.size()-1,ex);
    }
};