class Solution {
public:
    vector<int> check(string st1,int i,int j){
        if(i==j || j-i==1){
            string s="";
            for(int l=i;l<=j;l++){
                s+=st1[l];
            }
            return {stoi(s)};
        }
        vector<int>ans;
        for(int k=i;k<=j;k++){
            if(st1[k]=='+' || st1[k]=='*' || st1[k]=='-'){
                vector<int> l=check(st1,i,k-1);
                vector<int> r=check(st1,k+1,j);
                if(st1[k]=='+'){
                    for(auto x:l){
                        for(auto y:r){
                            ans.push_back(x+y);
                        }
                    }
                }
                if(st1[k]=='-'){
                    for(auto x:l){
                        for(auto y:r){
                            ans.push_back(x-y);
                        }
                    }
                }
                if(st1[k]=='*'){
                    for(auto x:l){
                        for(auto y:r){
                            ans.push_back(x*y);
                        }
                    }
                }
            }
        }
        return ans;

    }
    vector<int> diffWaysToCompute(string e) {
        return check(e,0,e.size()-1);
    }
};