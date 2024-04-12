class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        int v1[n];
        int v2[n]; 
        int lmax=v[0];
        v1[0]=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]>=lmax){
                lmax=v[i];
                v1[i]=lmax;
            }
            v1[i]=lmax;
        }
        int rmax=v[n-1];
        for(int i=v.size()-2;i>=0;i--){
            if(v[i]>=rmax){
                rmax=v[i];
            }
            v2[i]=rmax;
        }
        cout<<"v1= ";
        for(int i=0;i<n;i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        cout<<"v2= ";
        for(int i=0;i<n;i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
        int res=0;
        for(int i=1;i<v.size()-1;i++){
            res+=(min(v1[i],v2[i]))-v[i];
        }
        return res;
        
    }
};