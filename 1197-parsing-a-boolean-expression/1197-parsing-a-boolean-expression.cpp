class Solution {
public:
    bool check(int i , int j ,string e){
        if(i==j){
            return e[i]=='f'?false:true;
        }
        if(e[i]=='!'){
            return check(i+2,j-1,e)==true?false:true;
        }
        else if(e[i]=='&'){
            int count=0;
            bool ans=true;
            int l=i+2,r=i+2;
            while(r<=j){
                if(e[r]=='('){
                    count++;
                }
                else if(e[r]==')'){
                    count--;
                }
                if(count==0 && (e[r+1]==',' || r+1==j)){
                    cout<<"next"<<endl;
                    ans=ans&check(l,r,e);
                    l=r+2;
                    r++;
                }
                r++;
            }
            return ans;
        }
        int count=0;
        bool ans=false;
        int l=i+2,r=i+2;
        while(r<=j){
            if(e[r]=='('){
                count++;
            }
            if(e[r]==')'){
                count--;
            }
            if(count==0 && (e[r+1]==',' || r+1==j)){
                ans=ans|check(l,r,e);
                l=r+2;
                r++;
            }
            r++;
        }
        return ans;
    }
    bool parseBoolExpr(string e) {
        return check(0,e.size()-1,e);
    }
};