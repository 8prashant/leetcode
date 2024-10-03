class RangeModule {
public:
    map<int,int>m;
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        auto it=m.lower_bound(left);
        while(it!=m.end() && right>=it->second){
            left=min(left,it->second);
            right=max(right,it->first);
            it=m.erase(it);
        }
        m[right]=left;
    }
    
    bool queryRange(int left, int right) {
        auto it=m.lower_bound(left);
        if(it==m.end()){
            return false;
        }
        if(left>=it->second && right<=it->first){
            return true;
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        left+=1;
        right-=1;
        auto it=m.lower_bound(left);
        int l1,r1,l2,r2;
        while(it!=m.end() && right>=it->second){
            l1=min(left,it->second);
            r1=max(left,it->second);
            l2=min(right,it->first);
            r2=max(right,it->first);
            if(l1==it->second){
                m[r1-1]=l1;
            }
            if(r2==it->first){
                m[r2]=l2+1;
                break;
            }
            left=l2+1;
            right=r2;
            it=m.erase(it);        
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */