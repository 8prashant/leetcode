class Solution {
public:

    int check(vector<int> v2){
        int res=0;
        stack<int> s;
        for(int i=0;i<v2.size();i++){
        while(s.empty()==false && v2[i]<=v2[s.top()]){
            int tem=s.top();
            s.pop();
            int curr=v2[tem]*(s.empty()? i:(i-s.top()-1));
            res=max(res,curr);
        }
            s.push(i);
        }
            while(s.empty()==false){
                int tem=s.top();
                s.pop();
                int curr= v2[tem]*(s.empty()? v2.size():v2.size()-s.top()-1);
                res=max(res,curr);
            }
        return res;
    }
    int maximalRectangle(vector<vector<char>> &v) {
        int r=v.size();
        int c=v[0].size();
        cout<<"r="<<r<<" "<<"c="<<c<<endl;
        vector<int> v2;
        int res=0;
        for(int i=0;i<c;i++){
            int a=v[0][i]==48? 0:1;
            v2.push_back(a);
        }
        res=max(res,check(v2));
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                v2[j]=v[i][j]==48? 0:v2[j]+1;
            }
            res=max(res,check(v2));
        }
        return res;
        
    }
};