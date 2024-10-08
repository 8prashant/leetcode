class Solution {
public:
    int minSwaps(string s) {
        stack<char>ss;
        for(auto x:s){
            if(ss.empty()){
                ss.push(x);
            }
            else if(ss.top()=='[' && x==']'){
                ss.pop();
            }
            else{
                ss.push(x);
            }
        }
        if(ss.size()==2){
            return 1;
        }
        return ceil((double)ss.size()/4);
    }
};