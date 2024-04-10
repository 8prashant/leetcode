class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        vector<int> v;
        queue<int> q;
        sort(d.begin(),d.end());
        int a;
        q.push(d[d.size()-1]);
        for(int i=d.size()-2;i>=0;i--){
            a = q.front();
            q.pop();
            q.push(a);
            q.push(d[i]);
        }
        while(!q.empty()){
            v.push_back(q.front());
            q.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};