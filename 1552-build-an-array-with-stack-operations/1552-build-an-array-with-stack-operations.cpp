class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int s=target.size();
        string s1="Push";
        string s2="Pop";
        int j=0;
        for(int i=1;i<=target[s-1];i++){
            if(i==target[j]){
                j++;
                v.push_back(s1);
            }
            else{
                v.push_back(s1);
                v.push_back(s2);
            }
        }
        return v;

    }
};