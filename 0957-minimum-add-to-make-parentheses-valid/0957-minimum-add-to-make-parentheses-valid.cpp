class Solution {
public:
    int minAddToMakeValid(string st) {
        stack<char>s;
        for(auto x:st){
            if(s.empty()){
                s.push(x);
            }
            else if(s.top()=='(' && x==')'){
                s.pop();
            }
            else{
                s.push(x);
            }
        }
        return s.size();
    }
};