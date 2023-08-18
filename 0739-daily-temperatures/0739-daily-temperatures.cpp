class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> v(temp.size(),0);
        stack<int>s;
        s.push(temp.size()-1);
        for(int i=temp.size()-2;i>=0;i--){
            while(!s.empty() &&temp[s.top()]<=temp[i]){
                s.pop();
            }
            v[i]=s.size()==0?0:s.top()-i;
            s.push(i);
        }
        return v;
    }
};