class MyCalendar {
public:
    map<int,int>m;
    MyCalendar() {  
    }
    bool book(int start, int end) {
        auto it=m.lower_bound(start);
        if(it==m.end()){
            m[end-1]=start;
            return true;
        }
        if(it->first==start){
            return false;
        }
        else{
            if(end-1<it->second){
                m[end-1]=start;
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