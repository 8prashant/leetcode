class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<=0 ||t.size()<=0 || s.size()<t.size()){
            return "";
        }
        unordered_map<int,int>m;
        for(auto x:t){
            m[x]++;
        }
        int i=0,j=0,count=t.size();
        int st,e;
        int ans=INT_MAX;
        while(j<s.size()){
            if(m[s[j]]>0){
                count--;
            }
            m[s[j]]--;
            while(count==0){
                if(m[s[i]]>=0){
                    count++;
                }
                m[s[i]]++;
                if((j-i+1)<ans){
                    ans=(j-i+1);
                    st=i;
                    e=j;
                }
                i++;
            }
            j++;
        }
        if(ans==INT_MAX){
            return "";
        }
        string res;
        for(int i=st;i<=e;i++){
            res+=s[i];
        }
        return res;
    }
};