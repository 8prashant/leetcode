class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(auto x:wordList){
            s.insert(x);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int ma=0;
        while(!q.empty()){
            string st1=q.front().first;
            int l=q.front().second;
            q.pop();
            if(st1==endWord){
                ma=l;
                break;
            }
            for(int i=0;i<st1.size();i++){
                string ch=st1;
                int j='a';
                int end='z';
                while(j<=end){
                    ch[i]=char(j);
                    auto it=s.find(ch);
                    if(it!=s.end()){
                        s.erase(ch);
                        q.push({ch,l+1});
                    }
                    j++;
                }
            }
        }
        return ma;
    }
};