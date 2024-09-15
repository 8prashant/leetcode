class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        set<string>s;
        for(auto x:wl){
            s.insert(x);
        }
        if(s.find(ew)==s.end()){
            return 0;
        }
        queue<string>q;
        q.push(bw);
        if(s.find(bw)!=s.end()){
            s.erase(bw);
        }
        int ans=0;
        while(!q.empty()){
            ans++;
            int si=q.size();
            for(int i=0;i<si;i++){
                string a=q.front();
                q.pop();
                if(a==ew){
                    return ans;
                }
                for(int j=0;j<a.size();j++){
                    for(char l='a';l<='z';l++){
                        string b=a.substr(0,j)+l+a.substr(j+1);
                        if(s.find(b)!=s.end()){
                            q.push(b);
                            s.erase(b);
                        }
                    }
                }
            }
        }
        return 0;

    }
};