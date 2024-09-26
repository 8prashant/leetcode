class MyCalendar {
public:
    vector<int>v;
    unordered_map<int,int>m;
    MyCalendar() {
    }
    bool book(int start, int end) {
        auto it=lower_bound(v.begin(),v.end(),start);
        if(it==v.end()){
            m[end-1]=start;
            v.push_back(end-1);
            return true;
        }
        if(*it==start){
            return false;
        }
        else{
            if(end-1<m[*it]){
                m[end-1]=start;
                v.push_back(end-1);
                sort(v.begin(),v.end());
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */