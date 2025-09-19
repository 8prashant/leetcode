class Spreadsheet {
public:
    unordered_map<string, int> mp;
    Spreadsheet(int rows) {
        mp.clear();
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        string first = "", second = "";
        for(int i = 1;i< formula.length(); i++){
            if(formula[i] == '+'){
                first = second;
                second = "";
            }else{
                second += formula[i];
            }
        }
        int sum = 0;
        // cout << first << " " << second << endl;
        if(isdigit(first[0])){
            sum = stoi(first);
        }else{
            sum = mp[first];
        }
        if(isdigit(second[0])){
            sum += stoi(second);
        }else{
            sum+= mp[second];
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */